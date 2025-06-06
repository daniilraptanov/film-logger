import Header from "../../shared/Header";
import LogsTable from "./LogsTable";

const mock = Array.from({length: 100}, (_obj => {
    return {
        iso: 100500,
        aperture: 100500,
        shutter: 100500,
        lux: 100500,
        cct: 100500,
        ev: 100500,
    }
}));

const LogsPage = () => {
    return (
        <>
            <Header />
            <LogsTable records={mock} />
        </>
    );
};

export default LogsPage;

