#include <stdio.h>
#include "typewise-alert.h"

char const *alertMessages[TOTAL_ALERTS] = {"NORMAL", "TOO_LOW", "TOO_HIGH"};

Status sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  
  return SENT;
}

Status sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is %s\n", alertMessages[breachType]);
  
  return SENT;
}