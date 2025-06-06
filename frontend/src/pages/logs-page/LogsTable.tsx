import { FC, useMemo, useState } from "react";
import { LightRecord } from "../../domain/models/LightRecord";
import { ChevronDownIcon, ChevronUpIcon } from "@heroicons/react/20/solid";

interface LogsTableProps {
    records: LightRecord[];
}

type SortKey = keyof LightRecord;

const LogsTable: FC<LogsTableProps> = ({ records }) => {
    const [page, setPage] = useState(1);
    const [perPage, setPerPage] = useState(10);
    const [sortKey, setSortKey] = useState<SortKey>("ev");
    const [sortAsc, setSortAsc] = useState(true);

    const sortedRecords = useMemo(() => {
        const sorted = [...records].sort((a, b) =>
            sortAsc
                ? a[sortKey] - b[sortKey]
                : b[sortKey] - a[sortKey]
        );
        return sorted;
    }, [records, sortKey, sortAsc]);

    const paginated = useMemo(() => {
        const start = (page - 1) * perPage;
        return sortedRecords.slice(start, start + perPage);
    }, [sortedRecords, page, perPage]);

    const totalPages = Math.ceil(records.length / perPage);

    const handleSort = (key: SortKey) => {
        if (sortKey === key) setSortAsc(!sortAsc);
        else {
            setSortKey(key);
            setSortAsc(true);
        }
    };

    return (
        <div className="px-4 py-6 max-w-6xl mx-auto">
            <div className="overflow-x-auto rounded shadow max-h-[70vh] overflow-y-auto">
                <table className="overflow-auto relative min-w-full bg-gray-800 text-white border border-gray-700">
                    <thead>
                        <tr className="text-sm text-gray-200">
                            <th className="sticky top-0 z-10 bg-gray-700 px-4 py-2 cursor-pointer select-none text-left whitespace-nowrap">
                                <div className="flex items-center gap-1">#</div>
                            </th>
                            {["iso", "aperture", "shutter", "lux", "cct", "ev"].map((key) => (
                                <th
                                    key={key}
                                    onClick={() => handleSort(key as SortKey)}
                                    className="sticky top-0 z-10 bg-gray-700 px-4 py-2 cursor-pointer select-none text-left whitespace-nowrap"
                                >
                                    <div className="flex items-center gap-1">
                                        {key.toUpperCase()}
                                        {sortKey === key ? (
                                            sortAsc ? (
                                                <ChevronUpIcon className="w-4 h-4" />
                                            ) : (
                                                <ChevronDownIcon className="w-4 h-4" />
                                            )
                                        ) : null}
                                    </div>
                                </th>
                            ))}
                        </tr>
                    </thead>
                    <tbody>
                        {paginated.map((record, idx) => (
                            <tr
                                key={idx}
                                className="border-t border-gray-700 hover:bg-gray-700"
                            >
                                <td className="px-4 py-2">{idx + 1}</td>
                                <td className="px-4 py-2">{record.iso}</td>
                                <td className="px-4 py-2">{record.aperture}</td>
                                <td className="px-4 py-2">{record.shutter}</td>
                                <td className="px-4 py-2">{record.lux}</td>
                                <td className="px-4 py-2">{record.cct}</td>
                                <td className="px-4 py-2">{record.ev}</td>
                            </tr>
                        ))}
                        {paginated.length === 0 && (
                            <tr>
                                <td colSpan={6} className="text-center py-4 text-gray-400">
                                    Даних нема
                                </td>
                            </tr>
                        )}
                    </tbody>
                </table>
            </div>

            {/* Pagination + PerPage */}
            <div className="sticky bottom-4 bg-gray-900 mt-4 flex flex-col sm:flex-row items-center justify-between gap-4">
                <div className="flex items-center gap-2">
                    <span className="text-sm text-gray-300">Показувати по:</span>
                    <select
                        value={perPage}
                        onChange={(e) => {
                            setPage(1);
                            setPerPage(Number(e.target.value));
                        }}
                        className="bg-gray-700 text-white px-2 py-1 rounded"
                    >
                        {[10, 50, 100, 1000].map((n) => (
                            <option key={n} value={n}>{n}</option>
                        ))}
                    </select>
                </div>

                <div className="flex items-center gap-3">
                    <button
                        onClick={() => setPage((p) => Math.max(1, p - 1))}
                        disabled={page === 1}
                        className="text-white bg-gray-700 hover:bg-gray-600 disabled:opacity-40 px-3 py-1 rounded"
                    >
                        Назад
                    </button>
                    <span className="text-sm text-gray-300">
                        Сторінка {page} з {totalPages} | Записів: {records.length}
                    </span>
                    <button
                        onClick={() => setPage((p) => Math.min(totalPages, p + 1))}
                        disabled={page === totalPages}
                        className="text-white bg-gray-700 hover:bg-gray-600 disabled:opacity-40 px-3 py-1 rounded"
                    >
                        Вперед
                    </button>
                </div>
            </div>
        </div>
    );
};

export default LogsTable;
