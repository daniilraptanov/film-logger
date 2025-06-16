-- CreateTable
CREATE TABLE "LightRecord" (
    "id" UUID NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,
    "iso" INTEGER NOT NULL,
    "aperture" DOUBLE PRECISION NOT NULL,
    "shutter" DOUBLE PRECISION NOT NULL,
    "lux" DOUBLE PRECISION NOT NULL,
    "cct" DOUBLE PRECISION NOT NULL,
    "ev" DOUBLE PRECISION NOT NULL,

    CONSTRAINT "LightRecord_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Sensor" (
    "id" UUID NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,
    "type" SMALLINT NOT NULL,
    "gain" INTEGER NOT NULL,
    "integrationTime" INTEGER NOT NULL,

    CONSTRAINT "Sensor_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Logging" (
    "id" UUID NOT NULL,
    "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "updatedAt" TIMESTAMP(3) NOT NULL,
    "streamIntervalSec" INTEGER NOT NULL,

    CONSTRAINT "Logging_pkey" PRIMARY KEY ("id")
);

-- CreateIndex
CREATE UNIQUE INDEX "Sensor_type_key" ON "Sensor"("type");
