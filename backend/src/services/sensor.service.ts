import { ISensorModel, ISensorService } from "../domain/sensor.type";
import { SimpleService } from "./simple.service";
import { ISensorDTO } from "../domain/dto/sensor.dto";

class SensorServiceImpl extends SimpleService implements ISensorService {
    async updateSensor(dto: ISensorDTO): Promise<ISensorModel> {
        return this._dbInstance.sensor.update({data: dto, where: { type: dto.type }})
    }

    async getAllSensors(): Promise<ISensorModel[]> {
        return this._dbInstance.sensor.findMany();
    }
}

export function sensorServiceFactory(dbInstance = null): ISensorService {
  return new SensorServiceImpl(dbInstance);
}
