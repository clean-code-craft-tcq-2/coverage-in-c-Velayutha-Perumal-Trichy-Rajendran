#pragma once

typedef float Limit;

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  TOTAL_SUPPORTED_COOLING_TYPE
} CoolingType;

typedef struct {
  double upperLimit;
  double lowerLimit;
} BreachLimits breachLimits[TOTAL_SUPPORTED_COOLING_TYPE] = {
																{0.0, 35.0},
																{0.0, 45.0},
																{0.0, 40.0}
															};
															
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
Limit getBreachUpperLimit (CoolingType coolingType);
Limit getBreachLowerLimit (CoolingType coolingType);