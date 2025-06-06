import { FC } from "react";
import { CartesianGrid, Line, LineChart, XAxis, YAxis } from "recharts";
import { lightRecordsMock } from "../../mock-data/light-records.mock";

interface ChartProps {}

const Chart: FC<ChartProps> = (props) => {
    return (
        <LineChart width={500} height={300} data={lightRecordsMock}>
            <XAxis dataKey="name"/>
            <YAxis/>
            <CartesianGrid stroke="#eee" strokeDasharray="5 5"/>
            <Line type="monotone" dataKey="uv" stroke="#8884d8" />
            <Line type="monotone" dataKey="pv" stroke="#82ca9d" />
        </LineChart>
    );
};

export default Chart;
