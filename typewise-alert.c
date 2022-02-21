#include "typewise-alert.h"
#include "cooling-types-limit-map.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
	BreachType breachType = NORMAL;

	if(value < lowerLimit) 
	{
		breachType = TOO_LOW;
	}
	if(value > upperLimit) 
	{
		breachType = TOO_HIGH;
	}
	  return breachType;
}

/* BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  switch(coolingType) {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
} */

Limit getBreachUpperLimit (CoolingType coolingType)
{
	return breachLimits[coolingType].upperLimit;
}

Limit getBreachLowerLimit (CoolingType coolingType)
{
	return breachLimits[coolingType].lowerLimit;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
	BreachLimits limits;
	
	limits.lowerLimit = getBreachUpperLimit (coolingType);
	limits.upperLimit = getBreachLowerLimit (coolingType);
	
	return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);	
}
 
Status sendAlertIfBreach (AlertTarget alertTarget, BreachType breachType)
{
	Status alertStatus = NOT_SENT;
	alertTarget sendAlert = alertsTo[alertTarget];
	
	if (breachType)
	{
		alertStatus = sendAlert(breachType);
	}
	
	return alertStatus;
}

/* checkBreachStatus
void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}
 */