import { SensorType } from "../enums/sensor-type.enum";
import { ISimpleDTO } from "./simple.dto";

export interface ISensorDTO extends ISimpleDTO {
    type: SensorType;
    gain: number;
    integrationTime: number;
}
