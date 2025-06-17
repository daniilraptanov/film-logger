import { ISimpleDTO } from "./simple.dto";

export interface ILightRecordDTO extends ISimpleDTO {
    iso: number
    aperture: number;
    shutter: number;
    lux: number;
    cct: number;
    ev: number;
}
