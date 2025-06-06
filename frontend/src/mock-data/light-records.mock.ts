import { LightRecord } from "../domain/models/LightRecord";

export const lightRecordsMock: LightRecord[] = Array.from({length: 100}, (_obj => {
    return {
        iso: 100500,
        aperture: 100500,
        shutter: 100500,
        lux: 100500,
        cct: 100500,
        ev: 100500,
        datetime: "2025-06-06T17:42:00",
    }
}));
