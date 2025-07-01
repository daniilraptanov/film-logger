import { SensorType } from "../domain/enums/SensorType";
import { Logging, Sensor } from "../domain/models/Settings";
import { ApiResponse } from "../domain/tools/ApiResponse";
import { PaginateModel } from "../domain/tools/PaginateModel";
import { ApiService } from "./api-service";

class SettingsService extends ApiService {
    DEFAULT_SENSOR_OBJ: Sensor = {
        type: SensorType.TCS34725,
        gain: 0,
        integrationTime: 0,
    }

    DEFAULT_LOGGING_OBJ: Logging = {
        id: "",
        streamIntervalSec: 0,
    }

    async updateSensor(json: Sensor): Promise<boolean> {
        try {
            const response: ApiResponse<null> = await this.API.patch("api/v1/sensors", { json }).json();
            return !!response?.message;
        } catch {
            return false;
        }
    }

    async updateLogging(json: Logging): Promise<boolean> {
        try {
            const response: ApiResponse<null> = await this.API.patch("api/v1/logging", { json }).json();
            return !!response?.message;
        } catch {
            return false;
        }
    }

    async getSensor(type: SensorType): Promise<Sensor> {
        try {
            const response: ApiResponse<PaginateModel<Sensor>> = await this.API.get("api/v1/sensors").json();
            return response?.data?.rows?.find(item => item?.type === type) || this.DEFAULT_SENSOR_OBJ;
        } catch {
            return this.DEFAULT_SENSOR_OBJ;
        }
    }

    async getLogging(): Promise<Logging> {
        try {
            const response: ApiResponse<Logging> = await this.API.get("api/v1/logging").json();
            return response?.data || this.DEFAULT_SENSOR_OBJ;
        } catch {
            return this.DEFAULT_LOGGING_OBJ;
        }
    }
}

export function settingsServiceFactory() {
    return new SettingsService();
}
