import { Route, Routes } from "react-router-dom";
import LogsPage from "./pages/logs-page/LogsPage";
import ChartsPage from "./pages/charts-page/ChartsPage";
import SettingsPage from "./pages/settings-page/SettingsPage";
import { useLightRecordsStore } from "./store/useLightRecordsStore";
import { useEffect } from "react";
import { useSettingsStore } from "./store/useSettingsStore";

const App = () => {
    const { page, limit, fetchRecords } = useLightRecordsStore();
    const { fetchSettings } = useSettingsStore();

    useEffect(() => {
        fetchSettings();
        fetchRecords();
    }, [page, limit]);

    return (
        <Routes>
            <Route path="/" element={<LogsPage />} />
            <Route path="/logs" element={<LogsPage />} />
            <Route path="/charts" element={<ChartsPage />} />
            <Route path="/settings" element={<SettingsPage />} />
            <Route path="*" element={<h1>На жаль сторінку не знайдено</h1>} />
        </Routes>
    );
};

export default App;
