import { Route, Routes } from "react-router-dom";

const App = () => {
    return (
        <Routes>
            <Route path="/" element={<MainPage />}>
                <Route index element={<PatientsTable patients={patients} />} />
                <Route path="form/:formId" element={<FormSection />} />
            </Route>
            <Route path="*" element={<h1>404</h1>} />
        </Routes>
    );
};

export default App;
