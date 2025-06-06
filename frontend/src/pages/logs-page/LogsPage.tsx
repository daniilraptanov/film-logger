import { lightRecordsMock } from "../../mock-data/light-records.mock";
import Header from "../../shared/Header";
import LogsTable from "./LogsTable";


const LogsPage = () => {
    return (
        <>
            <Header />
            <LogsTable records={lightRecordsMock} />
        </>
    );
};

export default LogsPage;

