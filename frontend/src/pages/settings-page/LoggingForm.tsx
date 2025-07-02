import { useEffect, useState } from "react";
import { useSettingsStore } from "../../store/useSettingsStore";
import usePopupTooltip from "../../hooks/usePopupTooltip";

const LoggingForm = () => {
    const { logging, updateLogging } = useSettingsStore();
    
    const [streamIntervalSec, setStreamIntervalSec] = useState<number>(logging.streamIntervalSec);

    const { setActive, Tooltip } = usePopupTooltip("Дані збережено");

    useEffect(() => {
        setStreamIntervalSec(logging.streamIntervalSec);
    }, [logging]);

    const sendData = async () => {
        const result = await updateLogging({ streamIntervalSec });
        setActive(result);
    };

    return (
        <div className="flex flex-col w-full max-w-md bg-gray-900 p-6 rounded-lg shadow-md text-white">
            {Tooltip}
            <h2 className="text-xl font-semibold mb-4">Частота потокового логування</h2>
            <div className="mb-4">
                <label className="block mb-1">Інтервал (секунди)</label>
                <input
                    type="number"
                    value={streamIntervalSec}
                    onChange={(e) => setStreamIntervalSec(Number(e.target.value))}
                    className="w-full p-2 bg-gray-800 rounded border border-gray-700"
                />
            </div>
            <button
                type="submit"
                onClick={sendData}
                className="self-center mt-auto bg-green-700 hover:bg-green-600 text-white py-2 px-4 rounded"
            >
                Зберегти
            </button>
        </div>
    );
};

export default LoggingForm;
