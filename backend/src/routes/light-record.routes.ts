import { Router } from "express";
import { validateCSV, validateParams } from "../middleware/validate-params.middleware";
import { paginationSchema } from "../schemas/pagination.schemas";
import { lightRecordSchema } from "../schemas/light-record.schemas";
import { LightRecordController } from "../controllers/light-record.controller";

const LightRecordRouter = Router();

LightRecordRouter.post(
  "/import-csv",
  validateCSV(lightRecordSchema),
  LightRecordController.importCSV
);

LightRecordRouter.get(
  "/",
  validateParams(paginationSchema),
  LightRecordController.getRecords
);

export { LightRecordRouter };
