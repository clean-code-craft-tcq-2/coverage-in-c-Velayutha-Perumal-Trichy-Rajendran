#pragma once

typedef float Limit;
#define PASSIVE_COOLING_UP_LIMIT		35.0
#define PASSIVE_COOLING_LO_LIMIT		0.0
#define HI_ACTIVE_COOLING_UP_LIMIT		45.0
#define HI_ACTIVE_COOLING_LO_LIMIT		0.0
#define MED_ACTIVE_COOLING_UP_LIMIT		40.0
#define MED_ACTIVE_COOLING_LO_LIMIT		0.0

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  TOTAL_SUPPORTED_COOLING_TYPE
} CoolingType;

typedef struct __limit__{
  double upperLimit;
  double lowerLimit;
}BreachLimits;
													
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
Limit getBreachUpperLimit (CoolingType coolingType);
Limit getBreachLowerLimit (CoolingType coolingType);