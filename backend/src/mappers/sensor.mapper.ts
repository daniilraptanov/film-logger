import { ISensorModel } from "../domain/sensor.type";
import { ISensorDTO } from "../domain/dto/sensor.dto";
import { SimpleMapper } from "./simple.mapper";
import { IMapper } from "../domain/tools/mapper.type";

class SensorMapperImpl extends SimpleMapper<ISensorModel, ISensorDTO> implements IMapper<ISensorModel, ISensorDTO> {
    private _commonDTOFields = [
        "id",
        "createdAt",
        "updatedAt",
    ];
    protected _toDTOFields: string[] = [
        ...this._commonDTOFields,
        "type",
        "gain",
        "integrationTime",
    ];
}

export function sensorMapperFactory(): IMapper<ISensorModel, ISensorDTO> {
  return new SensorMapperImpl();
}
