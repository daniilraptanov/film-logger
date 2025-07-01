import { FC, useState } from "react";
import { Bar, BarChart, ResponsiveContainer, Tooltip, YAxis } from "recharts";
import { CHART_FIELDS, FieldKey } from "../../domain/models/LightRecord";
import { useLightRecordsStore } from "../../store/useLightRecordsStore";

interface ChartProps {}

const Chart: FC<ChartProps> = () => {
    const [yKey, setYKey] = useState<FieldKey>("cct");

    const { records } = useLightRecordsStore();

    return (
        <div className="w-full flex flex-col items-center justify-center px-4 gap-4">
            <div className="flex flex-wrap gap-4 bg-gray-800 p-4 rounded-lg mt-6">
                <div className="flex flex-col text-white">
                    <label className="mb-1 text-sm">Y вісь</label>
                    <select
                        value={yKey}
                        onChange={(e) => setYKey(e.target.value as FieldKey)}
                        className="bg-gray-700 px-3 py-1 rounded"
                    >
                        {CHART_FIELDS.map((key) => (
                            <option key={key} value={key}>{key}</option>
                        ))}
                    </select>
                </div>
            </div>

            <div className="w-full max-w-6xl bg-gray-900 p-4 rounded-lg shadow-lg">
                <ResponsiveContainer width="100%" height={400}>
                    <BarChart width={150} height={40} data={records.rows}>
                        <YAxis
                            stroke="#a1a1aa"
                            tick={{ fill: "#a1a1aa", fontSize: 14 }}
                            axisLine={{ stroke: "#374151" }}
                            tickLine={{ stroke: "#374151" }}
                        />
                        <Tooltip
                            contentStyle={{
                                backgroundColor: "#1f2937",
                                border: "none",
                                borderRadius: "0.5rem",
                                color: "#fff",
                                boxShadow: "0 2px 8px rgba(0,0,0,0.15)",
                                fontSize: "0.875rem"
                            }}
                            itemStyle={{
                                color: "#fff"
                            }}
                            labelStyle={{
                                color: "#a1a1aa"
                            }}
                            cursor={{ fill: "#374151", opacity: 0.6 }}
                        />
                        <Bar dataKey={yKey} fill="#8884d8" />
                    </BarChart>
                </ResponsiveContainer>
            </div>
        </div>
    );
};

export default Chart;
