import { Router } from "express";
import { validateParams } from "../middleware/validate-params.middleware";
import { sensorSchema } from "../schemas/sensor.schemas";
import { SensorController } from "../controllers/sensor.controller";

const SensorRouter = Router();

SensorRouter.patch(
  "/",
  validateParams(sensorSchema),
  SensorController.updateSensor
);

SensorRouter.get(
  "/",
  SensorController.getSensors
);

export { SensorRouter };
