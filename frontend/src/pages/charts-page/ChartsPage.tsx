import { lightRecordsMock } from "../../mock-data/light-records.mock";
import Header from "../../shared/Header";
import Chart from "./Chart";

const ChartsPage = () => {
    return (
        <>
            <Header />
            <Chart records={lightRecordsMock} />
        </>
    );
};

export default ChartsPage;
