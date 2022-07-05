#include <stdio.h>
#include <assert.h>
#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
 return (CheckTemp(float temperature) && CheckStateOfCharge(float soc) && CheckChargeRate(float chargeRate));
}
 
  int CheckTemp(float temperature){
    int result = E_OK;
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
  int result =  E_NOT_OK;
}
return result;
}
  
  int CheckStateOfCharge(float soc){
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
   int result =  E_NOT_OK;
}
return result;
   }

  int CheckChargeRate(float chargeRate){
   if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
  int result =  E_NOT_OK;
}
return result;
 
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
