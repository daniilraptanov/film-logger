import { ISensorDTO } from "./dto/sensor.dto";

export interface ISensorModel extends ISensorDTO {}

export interface ISensorService {
    updateSensor(dto: ISensorDTO): Promise<ISensorModel>;
    getAllSensors(): Promise<ISensorModel[]>;
}
