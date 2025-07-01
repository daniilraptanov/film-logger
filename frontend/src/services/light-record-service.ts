import { LightRecord } from "../domain/models/LightRecord";
import { ApiResponse } from "../domain/tools/ApiResponse";
import { PaginateModel } from "../domain/tools/PaginateModel";
import { ApiService } from "./api-service";

class LightRecordService extends ApiService {
    DEFAULT_RECORDS_PAGE: number = 1;
    DEFAULT_RECORDS_LIMIT: number = 10;
    DEFAULT_RECORDS_OBJ: PaginateModel<LightRecord> = {
        totalPage: 0,
        totalRows: 0,
        rows: [],
    }

    async getRecords(page: number, limit: number): Promise<PaginateModel<LightRecord>> {
        try {
            const response: ApiResponse<PaginateModel<LightRecord>> = await this.API
                .get(`api/v1/light-records?page=${page}&limit=${limit}`)
                .json();
            return response?.data;
        } catch {
            return this.DEFAULT_RECORDS_OBJ;
        }
    }
}

export function lightRecordServiceFactory() {
    return new LightRecordService();
}
