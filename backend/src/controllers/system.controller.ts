import { Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { logger } from "../handlers/logging.handler";

export class SystemController {
    @logger
    static async checkConnection(req: Request, res: Response) {        
        const { data } = ApiRequest.getValidatedParams(req) as { data: string };
        sendResponse(res, StatusCodes.OK, "Welcome to FilmLogger API!", data);    
    }
}
