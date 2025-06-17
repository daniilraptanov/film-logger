import { Router } from "express";
import { validateParams } from "../middleware/validate-params.middleware";
import { loggingSchema } from "../schemas/logging.schemas";
import { LoggingController } from "../controllers/logging.controller";

const LoggingRouter = Router();

LoggingRouter.patch(
  "/",
  validateParams(loggingSchema),
  LoggingController.updateLogging
);

LoggingRouter.get(
  "/",
  LoggingController.getLogging
);

export { LoggingRouter };
