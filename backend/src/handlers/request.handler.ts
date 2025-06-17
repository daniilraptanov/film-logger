import { Request } from "express";

export class ApiRequest {
    static getValidatedParams(req: Request) {
        return req["validatedParams"];
    }

    static setValidatedParams(req: Request, params) {
        req["validatedParams"] = params;
    }

    static getValidatedCSV(req: Request) {
        return req["validatedCSV"];
    }

    static setValidatedCSV(req: Request, params) {
        req["validatedCSV"] = params;
    }
}
