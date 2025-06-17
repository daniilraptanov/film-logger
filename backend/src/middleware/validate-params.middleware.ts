import { NextFunction, Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { ObjectSchema } from "joi";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { parse } from "csv-parse";

export const validateParams = (schema: ObjectSchema) => {
  return (req: Request, res: Response, next: NextFunction) => {
    const params = { ...req.body, ...req.query, ...req.params }
    const { error } = schema.validate(params);

    if (!error) {
      ApiRequest.setValidatedParams(req, params);
      next();
    }

    if (!error) {
      return;
    }

    if (!error.details[0].context.key) {
      return sendResponse(res, StatusCodes.BAD_REQUEST, "An error occurred.");
    }
    return sendResponse(res, StatusCodes.BAD_REQUEST, error.details[0].message);
  };
};


export const validateCSV = (schema: ObjectSchema, fileField = "file") => {
  return (req: Request, res: Response, next: NextFunction) => {
    const file = req[fileField];

    if (!file || !file.buffer) {
      return sendResponse(res, StatusCodes.BAD_REQUEST, "CSV file not provided.");
    }

    const rows: any[] = [];
    const parser = parse(file.buffer.toString(), {
      columns: true,
      skip_empty_lines: true,
      trim: true,
    });

    parser.on("readable", () => {
      let row;
      while ((row = parser.read()) !== null) {
        const { error } = schema.validate(row);
        if (error) {
          return parser.destroy(error);
        }
        rows.push(row);
      }
    });

    parser.on("error", (err) => {
      return sendResponse(res, StatusCodes.BAD_REQUEST, `CSV validation error: ${err.message}`);
    });

    parser.on("end", () => {
      ApiRequest.setValidatedCSV(req, rows);
      next();
    });
  };
};

