import { LightRecord } from "../domain/models/LightRecord";

export const lightRecordsMock: LightRecord[] = Array.from({length: 2000}, ((_, k) => {
    return {
        iso: 100,
        aperture: 2.8,
        shutter: 500,
        lux: k * 10,
        cct: k * 100,
        ev: 16,
        datetime: new Date("2025-06-06T17:42:00"),
    }
}));
