import { Router } from "express";
import { validateCSV, validateParams } from "../middleware/validate-params.middleware";
import { paginationSchema } from "../schemas/pagination.schemas";
import { simpleLightRecordSchema } from "../schemas/light-record.schemas";
import { LightRecordController } from "../controllers/light-record.controller";

const LightRecordRouter = Router();

LightRecordRouter.post(
  "/",
  validateCSV(simpleLightRecordSchema),
  LightRecordController.importCSV
);

LightRecordRouter.get(
  "/",
  validateParams(paginationSchema),
  LightRecordController.getRecords
);

export { LightRecordRouter };
