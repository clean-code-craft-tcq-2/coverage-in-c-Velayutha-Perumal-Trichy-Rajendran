#include "typewise-alert.h"
#include "cooling-types-limit-map.h"
#include <stdio.h>

sendAlert alertsTo[TOTAL_ALERT_TARGET] = {sendToController, sendToEmail};
BreachLimits breachLimits[TOTAL_SUPPORTED_COOLING_TYPE] = 	{
																{PASSIVE_COOLING_LO_LIMIT, PASSIVE_COOLING_UP_LIMIT},
																{HI_ACTIVE_COOLING_LO_LIMIT, HI_ACTIVE_COOLING_UP_LIMIT},
																{MED_ACTIVE_COOLING_LO_LIMIT, MED_ACTIVE_COOLING_UP_LIMIT}
															};

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
 
Status sendAlertIfBreach (AlertTarget targetAlert, BreachType breachType)
{
	Status alertStatus = NOT_SENT;
	sendAlert alert_callback = alertsTo[targetAlert];
	
	if (breachType)
	{
		alertStatus = alert_callback(breachType);
	}
	
	return alertStatus;
}