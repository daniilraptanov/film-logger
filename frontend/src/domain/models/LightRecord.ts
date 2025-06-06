export interface LightRecord {
    iso: number;
    aperture: number;
    shutter: number;
    lux: number;
    cct: number;
    ev: number;
    datetime: Date;
}

export const LOGS_FIELDS = ["iso", "aperture", "shutter", "lux", "cct", "ev"] as const;
export type SortKey = (typeof LOGS_FIELDS)[number];

export const CHART_FIELDS = ["iso", "aperture", "shutter", "lux", "cct", "ev"] as const;
export type FieldKey = (typeof CHART_FIELDS)[number];
