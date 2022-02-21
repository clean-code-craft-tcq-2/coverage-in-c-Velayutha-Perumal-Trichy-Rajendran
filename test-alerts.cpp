#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "cooling-types-limit-map.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(35, 20, 30) == TOO_HIGH);
  REQUIRE(inferBreach(29, 20, 30) == NORMAL);  
}

TEST_CASE("Check If upperlimits set properly") {
	REQUIRE(getBreachUpperLimit(PASSIVE_COOLING) == 35.0);
	REQUIRE(getBreachUpperLimit(HI_ACTIVE_COOLING) == 45.0);
	REQUIRE(getBreachUpperLimit(MED_ACTIVE_COOLING) == 40.0);
}

TEST_CASE("Check If lowerlimits set properly") {
	REQUIRE(getBreachLowerLimit(PASSIVE_COOLING) == 0.0);
	REQUIRE(getBreachLowerLimit(HI_ACTIVE_COOLING) == 0.0);
	REQUIRE(getBreachLowerLimit(MED_ACTIVE_COOLING) == 0.0);
}

TEST_CASE("infers the breach according to Cooling type") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1.0) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50.0) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35.0) == NORMAL);  
}

TEST_CASE("check whether the alert is sent if breached") {
  REQUIRE(sendAlertIfBreach(TO_CONTROLLER, TOO_LOW) == SENT);
  REQUIRE(sendAlertIfBreach(TO_EMAIL, TOO_HIGH) == SENT);
  REQUIRE(sendAlertIfBreach(TO_EMAIL, NORMAL) == NOT_SENT);  
}