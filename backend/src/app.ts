import express from "express";
import { Config } from "./config";
import { LightRecordRouter } from "./routes/light-record.routes";
import { SensorRouter } from "./routes/sensor.routes";
import { LoggingRouter } from "./routes/logging.routes";

const cors = require("cors");

const API_V1 = "/api/v1";
Config.setVariables();

const app = express();

app.use(cors());
app.use(express.json({ limit: `${Config.app.JSON_LIMIT_MB}mb` }));

// Public routes
app.use(`${API_V1}/light-records`, LightRecordRouter);
app.use(`${API_V1}/sensors`, SensorRouter);
app.use(`${API_V1}/logging`, LoggingRouter);

app.listen(Config.app.PORT, () => {
  try {
    return console.log(`server is listening on ${Config.app.PORT}`);
  } catch {
    return console.error(`server error (on ${Config.app.PORT})`);
  }
});
