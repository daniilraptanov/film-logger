import { ILoggingDTO } from "./dto/logging.dto";

export interface ILoggingModel extends ILoggingDTO {}

export interface ILoggingService {
    updateLogging(dto: ILoggingDTO): Promise<ILoggingModel>;
    getLogging(): Promise<ILoggingModel>;
}
