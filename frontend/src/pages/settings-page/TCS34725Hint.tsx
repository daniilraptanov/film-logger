import { QuestionMarkCircleIcon } from "@heroicons/react/24/outline";
import { FC, useState } from "react";
import ModalWindow from "../../shared/ModalWindow";

const TCS34725Hint: FC = () => {
    const [opened, setOpened] = useState(false);

    return (
        <>
            <QuestionMarkCircleIcon
                className="h-6 w-6 text-gray-400 hover:text-green-600 transition-colors cursor-pointer"
                title="Довідка по налаштуваннях"
                onClick={() => setOpened(true)}
            />
            <ModalWindow
                opened={opened}
                setOpened={setOpened}
                title="Налаштування сенсора TCS34725"
                body={
                <div className="space-y-6">
                <section>
                    <h3 className="font-mono font-semibold text-green-700 mb-2">Integration Time</h3>
                    <p className="text-sm text-gray-300 mb-2">
                        Час інтеграції визначає, як довго датчик збирає світло для кожного вимірювання. Довший час збільшує чутливість, але може призвести до перенасичення в яскравих умовах.
                    </p>
                    <div className="overflow-x-auto">
                    <table className="min-w-full text-xs border border-gray-200 rounded">
                        <thead>
                        <tr className="bg-gray-100 text-black">
                            <th className="px-2 py-1 font-mono font-semibold text-left">Constant</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Value</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Time (ms)</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Cycles</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Max Count</th>
                        </tr>
                        </thead>
                        <tbody className="font-mono">
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_2_4MS</td><td className="px-2 py-1">0xFF</td><td className="px-2 py-1">2.4</td><td className="px-2 py-1">1</td><td className="px-2 py-1">1024</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_24MS</td><td className="px-2 py-1">0xF6</td><td className="px-2 py-1">24.0</td><td className="px-2 py-1">10</td><td className="px-2 py-1">10240</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_50MS</td><td className="px-2 py-1">0xEB</td><td className="px-2 py-1">50.4</td><td className="px-2 py-1">21</td><td className="px-2 py-1">21504</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_60MS</td><td className="px-2 py-1">0xE7</td><td className="px-2 py-1">60.0</td><td className="px-2 py-1">25</td><td className="px-2 py-1">25700</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_101MS</td><td className="px-2 py-1">0xD6</td><td className="px-2 py-1">100.8</td><td className="px-2 py-1">42</td><td className="px-2 py-1">43008</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_120MS</td><td className="px-2 py-1">0xCE</td><td className="px-2 py-1">120.0</td><td className="px-2 py-1">50</td><td className="px-2 py-1">51200</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_154MS</td><td className="px-2 py-1">0xC0</td><td className="px-2 py-1">153.6</td><td className="px-2 py-1">64</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_180MS</td><td className="px-2 py-1">0xB5</td><td className="px-2 py-1">180.0</td><td className="px-2 py-1">75</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_199MS</td><td className="px-2 py-1">0xAD</td><td className="px-2 py-1">199.2</td><td className="px-2 py-1">83</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_240MS</td><td className="px-2 py-1">0x9C</td><td className="px-2 py-1">240.0</td><td className="px-2 py-1">100</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_300MS</td><td className="px-2 py-1">0x83</td><td className="px-2 py-1">300.0</td><td className="px-2 py-1">125</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_360MS</td><td className="px-2 py-1">0x6A</td><td className="px-2 py-1">360.0</td><td className="px-2 py-1">150</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_401MS</td><td className="px-2 py-1">0x59</td><td className="px-2 py-1">400.8</td><td className="px-2 py-1">167</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_420MS</td><td className="px-2 py-1">0x51</td><td className="px-2 py-1">420.0</td><td className="px-2 py-1">175</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_480MS</td><td className="px-2 py-1">0x38</td><td className="px-2 py-1">480.0</td><td className="px-2 py-1">200</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_499MS</td><td className="px-2 py-1">0x30</td><td className="px-2 py-1">499.2</td><td className="px-2 py-1">208</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_540MS</td><td className="px-2 py-1">0x1F</td><td className="px-2 py-1">540.0</td><td className="px-2 py-1">225</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_600MS</td><td className="px-2 py-1">0x06</td><td className="px-2 py-1">600.0</td><td className="px-2 py-1">250</td><td className="px-2 py-1">65535</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_INTEGRATIONTIME_614MS</td><td className="px-2 py-1">0x00</td><td className="px-2 py-1">614.4</td><td className="px-2 py-1">256</td><td className="px-2 py-1">65535</td></tr>
                        </tbody>
                    </table>
                    </div>
                    <p className="text-xs text-gray-400 mt-2">
                    <span className="font-mono">100ms</span> рівномірно ділиться на періоди 50Hz та 60Hz.
                    </p>
                </section>
                <section>
                    <h3 className="font-mono font-semibold text-green-700 mb-2">Gain</h3>
                    <p className="text-sm text-gray-300 mb-2">
                        Посилення підсилює сигнал датчика. Використовуйте більший коефіцієнт підсилення для умов низької освітленості, а менший - для уникнення перенасичення при яскравому світлі.
                    </p>
                    <div className="overflow-x-auto">
                    <table className="min-w-full text-xs border border-gray-200 rounded">
                        <thead>
                        <tr className="bg-gray-100 text-black">
                            <th className="px-2 py-1 font-mono font-semibold text-left">Constant</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Value</th>
                            <th className="px-2 py-1 font-mono font-semibold text-left">Description</th>
                        </tr>
                        </thead>
                        <tbody className="font-mono">
                        <tr><td className="px-2 py-1">TCS34725_GAIN_1X</td><td className="px-2 py-1">0x00</td><td className="px-2 py-1">No gain</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_GAIN_4X</td><td className="px-2 py-1">0x01</td><td className="px-2 py-1">4x gain</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_GAIN_16X</td><td className="px-2 py-1">0x02</td><td className="px-2 py-1">16x gain</td></tr>
                        <tr><td className="px-2 py-1">TCS34725_GAIN_60X</td><td className="px-2 py-1">0x03</td><td className="px-2 py-1">60x gain</td></tr>
                        </tbody>
                    </table>
                    </div>
                </section>
                </div>
            }/>
        </>
    );
};

export default TCS34725Hint;
