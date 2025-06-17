import { PrismaClient } from "@prisma/client";
import { Prisma } from "../database/prisma-instance";
import { IOffsetPagination } from "../domain/tools/service.type";

export abstract class SimpleService {
    protected _dbInstance: PrismaClient;
    protected static ALL_PAGES = -1;

    constructor(dbInstance: PrismaClient) {
        this._dbInstance = dbInstance || Prisma.instance;
    }

    
    protected calculateOffset(page: number, limit: number): IOffsetPagination {
        limit = Math.abs(limit);
        // const isAllPages = page === PaginationService.ALL_PAGES
        return {
            take: limit,
            skip: limit * (Math.abs(page) - 1)
        }
    }

    protected calculateTotalPage(totalRows: number, limit: number): number {
        if (totalRows <= 0 || limit <= 0) {
            return 0;
        }
        return Math.ceil(totalRows / limit);
    }
}

