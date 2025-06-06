import Header from "../../shared/Header";
import LoggingForm from "./LoggingForm";
import SensorsForm from "./SensorsForm";

const SettingsPage = () => {
    return (
        <>
            <Header />
            <div className="settings-page flex flex-col md:flex-row gap-6 justify-center items-stretch p-6">
                <SensorsForm />
                <LoggingForm />
            </div>
        </>
    );
};

export default SettingsPage;
