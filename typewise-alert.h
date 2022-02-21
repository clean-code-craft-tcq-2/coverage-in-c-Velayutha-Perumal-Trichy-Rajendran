#pragma once

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  TOTAL_ALERTS
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TOTAL_ALERT_TARGET
} AlertTarget;

typedef enum {
  NOT_SENT,
  SENT
} Status;

char *alertMessages[] = {"NORMAL", "TOO_LOW", "TOO_HIGH"};

typedef int (*alertTarget)(int);
alertTarget alertsTo[TOTAL_ALERT_TARGET] = {sendToController, sendToEmail};

Status sendToController(BreachType breachType);
Status sendToEmail(BreachType breachType);
Status sendAlertIfBreach (alertTarget sendAlert, BreachType breachType);
BreachType inferBreach(double value, double lowerLimit, double upperLimit);

/* typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter; */