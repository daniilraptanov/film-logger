import { ILoggingModel } from "../domain/logging.type";
import { ILoggingDTO } from "../domain/dto/logging.dto";
import { SimpleMapper } from "./simple.mapper";
import { IMapper } from "../domain/tools/mapper.type";

class LoggingMapperImpl extends SimpleMapper<ILoggingModel, ILoggingDTO> implements IMapper<ILoggingModel, ILoggingDTO> {
    private _commonDTOFields = [
        "id",
        "createdAt",
        "updatedAt",
    ];
    protected _toDTOFields: string[] = [
        ...this._commonDTOFields,
        "streamIntervalSec"
    ];
}

export function loggingMapperFactory(): IMapper<ILoggingModel, ILoggingDTO> {
  return new LoggingMapperImpl();
}
