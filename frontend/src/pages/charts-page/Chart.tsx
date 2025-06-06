import { FC, useState } from "react";
import { Line, LineChart, ResponsiveContainer, Tooltip, XAxis, YAxis } from "recharts";
import { LightRecord } from "../../domain/models/LightRecord";

interface ChartProps {
    records: LightRecord[]
}

const CHART_FIELDS = ["iso", "aperture", "shutter", "lux", "cct", "ev"] as const;
type FieldKey = (typeof CHART_FIELDS)[number];

const Chart: FC<ChartProps> = (props) => {
    const [xKey, setXKey] = useState<FieldKey>("lux");
    const [yKey, setYKey] = useState<FieldKey>("cct");

    return (
        <div className="w-full flex flex-col items-center justify-center px-4 gap-4">
            <div className="flex flex-wrap gap-4 bg-gray-800 p-4 rounded-lg">
                <div className="flex flex-col text-white">
                    <label className="mb-1 text-sm">X вісь</label>
                    <select
                        value={xKey}
                        onChange={(e) => setXKey(e.target.value as FieldKey)}
                        className="bg-gray-700 px-3 py-1 rounded"
                    >
                        {CHART_FIELDS.map((key) => (
                            <option key={key} value={key}>{key}</option>
                        ))}
                    </select>
                </div>
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
                    <LineChart data={props.records}>
                        <XAxis 
                            dataKey={xKey} 
                            stroke="#ccc" 
                        />
                        <YAxis stroke="#ccc" />
                        <Tooltip />
                        <Line type="monotone" dataKey={xKey} stroke="#8884d8" strokeWidth={2} dot={false} />
                        <Line type="monotone" dataKey={yKey} stroke="#82ca9d" strokeWidth={2} dot={false} />
                    </LineChart>
                </ResponsiveContainer>
            </div>
        </div>
    );
};

export default Chart;
