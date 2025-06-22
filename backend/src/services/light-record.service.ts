import { ILightRecordModel, ILightRecordService } from "../domain/light-record.type";
import { IPaginateModel } from "../domain/tools/service.type";
import { SimpleService } from "./simple.service";
import { INewLightRecordDTO } from "../domain/dto/light-record.dto";

class LightRecordServiceImpl extends SimpleService implements ILightRecordService {
    async saveRecords(records: INewLightRecordDTO[]): Promise<ILightRecordModel[]> {
        return Promise.all(
            records.filter(record => !record.synced).map(record => this._dbInstance.lightRecord.create({ data: {
                ...record,
                iso: parseInt(record.iso),
                aperture: parseFloat(record.aperture),
                shutter: parseFloat(record.shutter),
                lux: parseFloat(record.lux),
                cct: parseFloat(record.cct),
                ev: parseFloat(record.ev),
            } }))
        );
    }

    async getRecords(page: number, limit: number): Promise<IPaginateModel<ILightRecordModel>> {
        const { take, skip } = this.calculateOffset(page, limit);
        const [rows, totalRows] = await this._dbInstance.$transaction([
            this._dbInstance.lightRecord.findMany({ take, skip }),
            this._dbInstance.lightRecord.count()
        ]);
        return { 
            rows, 
            totalRows,
            totalPage: this.calculateTotalPage(totalRows, limit)
        };
    }
}

export function lightRecordServiceFactory(dbInstance = null): ILightRecordService {
  return new LightRecordServiceImpl(dbInstance);
}
