import Joi from "joi";

export const lightRecordSchema = Joi.object().keys({
    iso: Joi.number().required(),
    aperture: Joi.number().required(),
    shutter: Joi.number().required(),
    lux: Joi.number().required(),
    cct: Joi.number().required(),
    ev: Joi.number().required(),
});

export const lightRecordListSchema = Joi.object().keys({
    data: Joi.array().items(lightRecordSchema).min(1).max(100).required(),
});
