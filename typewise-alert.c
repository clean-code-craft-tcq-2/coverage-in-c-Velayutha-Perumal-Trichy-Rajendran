#include "typewise-alert.h"
#include "cooling-types-limit-map.h"
#include <stdio.h>

sendAlert alertsTo[TOTAL_ALERT_TARGET] = {sendToController, sendToEmail};

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
	return breachThreshold[coolingType].upperLimit;
}

Limit getBreachLowerLimit (CoolingType coolingType)
{
	return breachThreshold[coolingType].lowerLimit;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
	struct BreachLimits limits;
	
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