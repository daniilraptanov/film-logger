import { useState } from "react";

const LoggingForm = () => {
    const [intervalSec, setIntervalSec] = useState<number>(5);

    const handleSubmit = (e: React.FormEvent) => {
        e.preventDefault();
        console.log({ intervalSec });
    };

    return (
        <form
            onSubmit={handleSubmit}
            className="flex flex-col w-full max-w-md bg-gray-900 p-6 rounded-lg shadow-md text-white"
        >
            <h2 className="text-xl font-semibold mb-4">Частота потокового логування</h2>
            <div className="mb-4">
                <label className="block mb-1">Інтервал (секунди)</label>
                <input
                    type="number"
                    value={intervalSec}
                    onChange={(e) => setIntervalSec(Number(e.target.value))}
                    className="w-full p-2 bg-gray-800 rounded border border-gray-700"
                />
            </div>
            <button
                type="submit"
                className="self-center mt-auto bg-green-700 hover:bg-green-600 text-white py-2 px-4 rounded"
            >
                Зберегти
            </button>
        </form>
    );
};

export default LoggingForm;
