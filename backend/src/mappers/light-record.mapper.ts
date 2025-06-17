import { ILightRecordModel } from "../domain/light-record.type";
import { ILightRecordDTO } from "../domain/dto/light-record.dto";
import { SimpleMapper } from "./simple.mapper";
import { IMapper } from "../domain/tools/mapper.type";

class LightRecordMapperImpl extends SimpleMapper<ILightRecordModel, ILightRecordDTO> implements IMapper<ILightRecordModel, ILightRecordDTO> {
    private _commonDTOFields = [
        "id",
        "createdAt",
        "updatedAt",
    ];
    protected _toDTOFields: string[] = [
        ...this._commonDTOFields,
        "iso",
        "aperture",
        "shutter",
        "lux",
        "cct",
        "ev",
    ];
}

export function lightRecordMapperFactory(): IMapper<ILightRecordModel, ILightRecordDTO> {
  return new LightRecordMapperImpl();
}
