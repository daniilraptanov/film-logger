import { ISimpleDTO } from "./simple.dto";

export interface ILoggingDTO extends ISimpleDTO {
    streamIntervalSec: number;
}
