import Joi from "joi";

export const checkConnectionSchema = Joi.object().keys({
    data: Joi.string().required(),
});
