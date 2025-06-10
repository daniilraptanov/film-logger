import { Request, Response } from "express";
import { StatusCodes } from "http-status-codes";
import { logger } from "../handlers/logging.handler";
import { ApiRequest } from "../handlers/request.handler";
import { sendResponse } from "../handlers/response.handler";
import { AuctionMapperImpl } from "../mappers/auction.mapper";
import { auctionProcessServiceFactory } from "../services/auction-process.service";
import { auctionServiceFactory } from "../services/auction.service";
import { ICreateAuctionDTO, IPlainAuctionDTO } from "../domain/dto/auction.dto";

export class AuctionController {
    @logger
    static async createAuction(req: Request, res: Response) {
        const auctionProcessService = auctionProcessServiceFactory();
        const auctionMapper = new AuctionMapperImpl();

        const data: ICreateAuctionDTO = ApiRequest.getValidatedParams(req);
        const user = ApiRequest.getUserDTO(req);

        const auction = await auctionProcessService.createOrUpdateAuction(data, user.id, null);
        if (!auction) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR, "Auction was not created.");
        }

        sendResponse(res, StatusCodes.CREATED, "Auction was created.", auctionMapper.toDTO(auction));
    }

    @logger
    static async updateAuction(req: Request, res: Response) {
        const auctionProcessService = auctionProcessServiceFactory();
        const auctionMapper = new AuctionMapperImpl();

        const { id, ...data } = ApiRequest.getValidatedParams(req);
        const user = ApiRequest.getUserDTO(req);

        const auction = await auctionProcessService.createOrUpdateAuction(data as ICreateAuctionDTO, user.id, id);
        if (!auction) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR, "Auction was not updated.");
        }

        sendResponse(res, StatusCodes.OK, "Auction was updated.", auctionMapper.toDTO(auction));
    }

    @logger
    static async getAllAuctions(req: Request, res: Response) {
        const auctionService = auctionServiceFactory();
        const auctionMapper = new AuctionMapperImpl();

        const { 
            page, 
            limit, 
            getMainImage, 
            getLastRate,
            minRate,
            maxRate 
        } = ApiRequest.getValidatedParams(req);

        const auctions = await auctionService.getAllAuctions(page, limit, getMainImage, getLastRate, +minRate, +maxRate);
        if (!auctions) {
            return sendResponse(res, StatusCodes.INTERNAL_SERVER_ERROR);
        }

        sendResponse(res, StatusCodes.OK, "Auctions was returned.", {
            ...auctions,
            rows: auctions.rows.map(auction => auctionMapper.toDTO(auction))
        });
    }

    @logger
    static async getAuctionById(req: Request, res: Response) {
        const auctionService = auctionServiceFactory();
        const auctionMapper = new AuctionMapperImpl();

        const { id, getImages, getLastRate } = ApiRequest.getValidatedParams(req);
        const user = ApiRequest.getUserDTO(req);

        const auction = await auctionService.getAuctionById(id, getImages, getLastRate);
        if (!auction) {
            return sendResponse(res, StatusCodes.NOT_FOUND, "Auction not found.");
        }

        sendResponse(res, StatusCodes.OK, "Auction was returned.", auctionMapper.toExtendDTO(auction, user.id));
    }
}
