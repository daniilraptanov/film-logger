import Joi from "joi";

export const loggingSchema = Joi.object().keys({
    id: Joi.string().uuid({ version: "uuidv4" }).required(),
    streamIntervalSec: Joi.number().integer().required(),
});
