import { useState } from "react";

const SensorsForm = () => {
    const [gain, setGain] = useState<number>(4);
    const [integrationTime, setIntegrationTime] = useState<number>(100);

    const handleSubmit = (e: React.FormEvent) => {
        e.preventDefault();
        console.log({ gain, integrationTime });
    };

    return (
        <form
            onSubmit={handleSubmit}
            className="flex flex-col w-full max-w-md bg-gray-900 p-6 rounded-lg shadow-md text-white"
        >
            <h2 className="text-xl font-semibold mb-4">Налаштування TCS34725</h2>
            <div className="mb-4">
                <label className="block mb-1">Gain</label>
                <input
                    type="number"
                    value={gain}
                    onChange={(e) => setGain(Number(e.target.value))}
                    className="w-full p-2 bg-gray-800 rounded border border-gray-700"
                />
            </div>
            <div className="mb-4">
                <label className="block mb-1">Integration Time</label>
                <input
                    type="number"
                    value={integrationTime}
                    onChange={(e) => setIntegrationTime(Number(e.target.value))}
                    className="w-full p-2 bg-gray-800 rounded border border-gray-700"
                />
            </div>
            <button
                type="submit"
                className="self-center bg-green-700 hover:bg-green-600 text-white py-2 px-4 rounded"
            >
                Зберегти
            </button>
        </form>
    );
};

export default SensorsForm;
