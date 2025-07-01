export interface PaginateModel<T> {
    rows: T[];
    totalRows: number;
    totalPage: number;
}
