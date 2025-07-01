import { Route, Routes } from "react-router-dom";
import LogsPage from "./pages/logs-page/LogsPage";
import ChartsPage from "./pages/charts-page/ChartsPage";
import SettingsPage from "./pages/settings-page/SettingsPage";
import { useLightRecordsStore } from "./store/useLightRecordsStore";
import { useEffect } from "react";
import { useSettingsStore } from "./store/useSettingsStore";
import Loader from "./shared/Loader";
import { useAppStore } from "./store/useAppStore";
import NotFound from "./pages/NotFound";

const App = () => {
    const { page, limit, fetchRecords } = useLightRecordsStore();
    const { fetchSettings } = useSettingsStore();
    const { isLoading } = useAppStore();

    useEffect(() => {
        fetchSettings();
        fetchRecords();
    }, [page, limit]);

    if (isLoading) {
        return <Loader />
    }

    return (
        <Routes>
            <Route path="/" element={<LogsPage />} />
            <Route path="/logs" element={<LogsPage />} />
            <Route path="/charts" element={<ChartsPage />} />
            <Route path="/settings" element={<SettingsPage />} />
            <Route path="*" element={<NotFound />} />
        </Routes>
    );
};

export default App;
