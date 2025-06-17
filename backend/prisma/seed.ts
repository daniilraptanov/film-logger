import { PrismaClient } from '@prisma/client';
import { SensorType } from '../src/domain/enums/sensor-type.enum';

const prisma = new PrismaClient();

async function main() {
  await prisma.sensor.create({
    data: {
        type: SensorType.TCS34725,
        gain: 0,
        integrationTime: 214,
    },
  });

  await prisma.logging.create({
    data: {
        streamIntervalSec: 1,
    },
  });
}

main()
  .catch((e) => {
    console.error(e);
    process.exit(1);
  })
  .finally(async () => {
    await prisma.$disconnect();
  });
