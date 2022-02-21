#include <stdio.h>
#include "typewise-alert.h"

extern char *alertMessages[TOTAL_ALERTS];

Status sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  
  return SENT;
}

Status sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  
  printf("To: %s\n", recepient);
  printf("Hi, the temperature is %s\n", alertMessages[breachType]);
  
  /* switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %s\n", alertMessages[breachType]);
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  } */
  return SENT;
}