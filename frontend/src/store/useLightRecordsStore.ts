import { create } from 'zustand'
import { LightRecord } from '../domain/models/LightRecord';
import { lightRecordServiceFactory } from '../services/light-record-service';
import { PaginateModel } from '../domain/tools/PaginateModel';
import { withLoading } from './useAppStore';

type LightRecordsState = {
    page: number;
    limit: number;
    records: PaginateModel<LightRecord>;

    resetPage: () => void;
    setPrevPage: () => void;
    setNextPage: () => void;
    setLimit: (limit: number) => void;
    fetchRecords: () => Promise<void>;
}

const lightRecordService = lightRecordServiceFactory();

export const useLightRecordsStore = create<LightRecordsState>((set, get, state) => ({
    page: lightRecordService.DEFAULT_RECORDS_PAGE,
    limit: lightRecordService.DEFAULT_RECORDS_LIMIT,
    records: lightRecordService.DEFAULT_RECORDS_OBJ,

    resetPage: () => set({ page: lightRecordService.DEFAULT_RECORDS_PAGE }),
    setPrevPage: () => set({ page: Math.max(1, state.getState().page - 1) }),
    setNextPage: () => set({ page: Math.min(state.getState().records.totalPage, state.getState().page + 1) }),
    setLimit: (limit) => set({ limit }),

    fetchRecords: withLoading(async () => {
        const { page, limit } = get();
        const records = await lightRecordService.getRecords(page, limit);
        set({ records });
    }),
}));
