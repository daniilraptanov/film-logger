import { ILightRecordDTO } from "./dto/light-record.dto";
import { IPaginateModel } from "./tools/service.type";

export interface ILightRecordModel extends ILightRecordDTO {}

export interface ILightRecordService {
    saveRecords(records: ILightRecordDTO[]): Promise<ILightRecordModel[]>;
    getRecords(page: number, limit: number): Promise<IPaginateModel<ILightRecordModel>>;
}
