import { Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { logger } from "../handlers/logging.handler";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { loggingServiceFactory } from "../services/logging.service";
import { ILoggingDTO } from "../domain/dto/logging.dto";
import { loggingMapperFactory } from "../mappers/logging.mapper";

export class LoggingController {
    @logger
    static async updateLogging(req: Request, res: Response) {
        const loggingService = loggingServiceFactory();
        
        const data: ILoggingDTO = ApiRequest.getValidatedParams(req);
        const saved = await loggingService.updateLogging(data);
        if (!saved) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR, "Logging was not updated.");
        }
        
        sendResponse(res, StatusCodes.OK, "Logging was saved.");    
    }

    @logger
    static async getLogging(_req: Request, res: Response) {
        const loggingService = loggingServiceFactory();
        const loggingMapper = loggingMapperFactory();

        const logging = await loggingService.getLogging();
        if (!logging) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR);
        }

        sendResponse(res, StatusCodes.OK, "Loggings was returned.", loggingMapper.toDTO(logging));

    }
}
