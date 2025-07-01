import { SensorType } from "../enums/SensorType";

export interface Sensor {
    type: SensorType;
    gain: number;
    integrationTime: number;
}

export interface Logging {
    id: string;
    streamIntervalSec: number;
}
