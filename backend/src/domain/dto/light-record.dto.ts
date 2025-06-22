import { ISimpleDTO } from "./simple.dto";

export interface INewLightRecordDTO {
    iso: string;
    aperture: string;
    shutter: string;
    lux: string;
    cct: string;
    ev: string;
    synced: boolean;
}

export interface ILightRecordDTO extends ISimpleDTO {
    iso: number;
    aperture: number;
    shutter: number;
    lux: number;
    cct: number;
    ev: number;
}
