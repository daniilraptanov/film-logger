import { Router } from "express";
import { validateParams } from "../middleware/validate-params.middleware";
import { paginationSchema } from "../schemas/pagination.schemas";
import { lightRecordListSchema } from "../schemas/light-record.schemas";
import { LightRecordController } from "../controllers/light-record.controller";

const LightRecordRouter = Router();

LightRecordRouter.post(
  "/import",
  validateParams(lightRecordListSchema),
  LightRecordController.importRecords
);

LightRecordRouter.get(
  "/",
  validateParams(paginationSchema),
  LightRecordController.getRecords
);

export { LightRecordRouter };
