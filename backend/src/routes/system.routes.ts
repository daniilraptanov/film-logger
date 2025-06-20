import { Router } from "express";
import { validateParams } from "../middleware/validate-params.middleware";
import { checkConnectionSchema } from "../schemas/system.schemas";
import { SystemController } from "../controllers/system.controller";

const SystemRouter = Router();

SystemRouter.get(
  "/",
  validateParams(checkConnectionSchema),
  SystemController.checkConnection
);

export { SystemRouter };
