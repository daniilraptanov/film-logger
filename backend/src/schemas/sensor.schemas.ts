import Joi from "joi";
import { SensorType } from "../domain/enums/sensor-type.enum";

export const sensorSchema = Joi.object().keys({
    type: Joi.number().valid(SensorType.TCS34725).required(),
    gain: Joi.number().integer().optional(),
    integrationTime: Joi.number().integer().optional(),
});
