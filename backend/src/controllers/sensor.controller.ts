import { Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { logger } from "../handlers/logging.handler";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { sensorServiceFactory } from "../services/sensor.service";
import { ISensorDTO } from "../domain/dto/sensor.dto";
import { sensorMapperFactory } from "../mappers/sensor.mapper";

export class SensorController {
    @logger
    static async updateSensor(req: Request, res: Response) {
        const sensorService = sensorServiceFactory();
        
        const data: ISensorDTO = ApiRequest.getValidatedParams(req);
        const saved = await sensorService.updateSensor(data);
        if (!saved) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR, "Sensor was not updated.");
        }
        
        sendResponse(res, StatusCodes.OK, "Sensor was saved.");    
    }

    @logger
    static async getSensors(req: Request, res: Response) {
        const sensorService = sensorServiceFactory();
        const sensorMapper = sensorMapperFactory();

        const sensors = await sensorService.getAllSensors();
        if (!sensors) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR);
        }

        sendResponse(res, StatusCodes.OK, "Sensors was returned.", {
            rows: sensors.map(sensor => sensorMapper.toDTO(sensor))
        });

    }
}
