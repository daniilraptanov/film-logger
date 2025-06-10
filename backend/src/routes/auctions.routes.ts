import { Router } from "express";
import { AuctionController } from "../controllers/auction.controller";
import { checkAuctionOwner } from "../middleware/check-owner.middleware";
import { validateParams } from "../middleware/validate-params.middleware";
import {
  createAuctionSchema,
  getAllAuctionsSchema,
  getAuctionSchema,
  updateAuctionSchema,
} from "../schemas/auction.schemas";

const AuctionsRouter = Router();

AuctionsRouter.post(
  "/",
  validateParams(createAuctionSchema),
  AuctionController.createAuction
);

AuctionsRouter.get(
  "/",
  validateParams(getAllAuctionsSchema),
  AuctionController.getAllAuctions
);

AuctionsRouter.patch(
  "/:id",
  validateParams(updateAuctionSchema),
  checkAuctionOwner(),
  AuctionController.updateAuction
);

AuctionsRouter.get(
  "/:id",
  validateParams(getAuctionSchema),
  AuctionController.getAuctionById
);

export { AuctionsRouter };
