import Joi from "joi";

export const lightRecordSchema = Joi.object().keys({
    id: Joi.string().uuid({ version: "uuidv4" }).required(),
    iso: Joi.string().required(),
    aperture: Joi.string().required(),
    shutter: Joi.string().required(),
    lux: Joi.string().required(),
    cct: Joi.string().required(),
    ev: Joi.string().required(),
    synced: Joi.string().valid("0", "1").required(),
});

export const lightRecordListSchema = Joi.object().keys({
    data: Joi.array().items(lightRecordSchema).min(1).max(100).required(),
});
