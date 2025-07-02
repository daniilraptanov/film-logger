import { create } from 'zustand'
import { Logging, Sensor } from '../domain/models/Settings';
import { SensorType } from '../domain/enums/SensorType';
import { settingsServiceFactory } from '../services/settings-service';
import { withLoading } from './useAppStore';

type SettingsState = {
    tcs34725: Sensor;
    logging: Logging;

    updateTCS34725: (form: Partial<Sensor>) => Promise<boolean>;
    updateLogging: (form: Partial<Logging>) => Promise<boolean>;
    fetchSettings: () => Promise<void>;
}

const settingsService = settingsServiceFactory();

export const useSettingsStore = create<SettingsState>((set, get) => ({
    tcs34725: settingsService.DEFAULT_SENSOR_OBJ,
    logging: settingsService.DEFAULT_LOGGING_OBJ,

    updateTCS34725: withLoading(async (form: Partial<Sensor>) => {
        const tcs34725 = { ...form, type: SensorType.TCS34725 } as Sensor;
        const updated = await settingsService.updateSensor(tcs34725);
        if (updated) {
            set({ tcs34725 });
        }
        return updated;
    }),

    updateLogging: withLoading(async (form: Partial<Logging>) => {
        const logging = { ...form, id: get().logging.id } as Logging;
        const updated = await settingsService.updateLogging(logging);
        if (updated) {
            set({ logging });
        }
        return updated;
    }),

    fetchSettings: withLoading(async () => {
        const [tcs34725, logging] = await Promise.all([
            settingsService.getSensor(SensorType.TCS34725),
            settingsService.getLogging(),
        ]);
        set({ tcs34725, logging });
    }),
}));
