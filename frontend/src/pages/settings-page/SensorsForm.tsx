import { useEffect, useState } from "react";
import TCS34725Hint from "./TCS34725Hint";
import { useSettingsStore } from "../../store/useSettingsStore";
import usePopupTooltip from "../../hooks/usePopupTooltip";

const SensorsForm = () => {
    const { tcs34725, updateTCS34725 } = useSettingsStore();

    const [gain, setGain] = useState<number>(tcs34725.gain);
    const [integrationTime, setIntegrationTime] = useState<number>(tcs34725.integrationTime);

    const { setActive, Tooltip } = usePopupTooltip("Дані збережено");

    useEffect(() => {
        setGain(tcs34725.gain);
        setIntegrationTime(tcs34725.integrationTime);
    }, [tcs34725]);

    const sendData = async () => {
        const result = await updateTCS34725({ gain, integrationTime });
        setActive(result);
    };

    return (
        <div className="flex flex-col w-full max-w-md bg-gray-900 p-6 rounded-lg shadow-md text-white">
            {Tooltip}
            <div className="flex items-center justify-between mb-4">
                <h2 className="text-xl font-semibold">Налаштування TCS34725</h2>
                <TCS34725Hint />
            </div>
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
                type="button"
                onClick={sendData}
                className="self-center bg-green-700 hover:bg-green-600 text-white py-2 px-4 rounded"
            >
                Зберегти
            </button>
        </div>
    );
};

export default SensorsForm;
