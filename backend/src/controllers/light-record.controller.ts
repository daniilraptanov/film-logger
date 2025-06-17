import { Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { logger } from "../handlers/logging.handler";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { ILightRecordDTO } from "../domain/dto/light-record.dto";
import { lightRecordServiceFactory } from "../services/light-record.service";
import { lightRecordMapperFactory } from "../mappers/light-record.mapper";

export class LightRecordController {
    @logger
    static async importCSV(req: Request, res: Response) {
        const lightRecordService = lightRecordServiceFactory();
        
        const data: ILightRecordDTO[] = ApiRequest.getValidatedCSV(req);
        const saved = await lightRecordService.saveRecords(data);
        if (!saved) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR, "LightRecords was not saved.");
        }
        
        sendResponse(res, StatusCodes.CREATED, "LightRecords was saved.");    
    }

    @logger
    static async getRecords(req: Request, res: Response) {
        const lightRecordService = lightRecordServiceFactory();
        const lightRecordMapper = lightRecordMapperFactory();

        const { page, limit } = ApiRequest.getValidatedParams(req);
        const records = await lightRecordService.getRecords(page, limit);
        if (!records) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR);
        }

        sendResponse(res, StatusCodes.OK, "LightRecords was returned.", {
            ...records,
            rows: records.rows.map(record => lightRecordMapper.toDTO(record))
        });
    }
}
