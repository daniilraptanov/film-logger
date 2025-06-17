import { ILoggingModel, ILoggingService } from "../domain/logging.type";
import { SimpleService } from "./simple.service";
import { ILoggingDTO } from "../domain/dto/logging.dto";

class LoggingServiceImpl extends SimpleService implements ILoggingService {
    async updateLogging(dto: ILoggingDTO): Promise<ILoggingModel> {
        return this._dbInstance.logging.update({data: dto, where: { id: dto.id }})
    }

    async getLogging(): Promise<ILoggingModel> {
        return this._dbInstance.logging.findFirst();
    }
}

export function loggingServiceFactory(dbInstance = null): ILoggingService {
  return new LoggingServiceImpl(dbInstance);
}
