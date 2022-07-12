#include <stdio.h>
#include <assert.h>
#include "checker.h"

int ClassifyRange(float CurrentValue, int MinRange, int MaxRange)
 {
	   int result = E_OK;
  if(CurrentValue < MinRange || CurrentValue > MaxRange) 
	{
    result =  E_NOT_OK;
	}
  return result;
}


 
int ClassifyTemperature(float temperature)
{    
return ClassifyRange(temperature, 0, 45);
}

int CheckStateOfCharge(float soc)
{    
return ClassifyRange(soc, 20, 80);
}

 int CheckChargeRate(float chargeRate)
 {    
return ClassifyRange(chargeRate, 0.8, 1);
}
  
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
 return (ClassifyTemperature(temperature) && CheckStateOfCharge(soc) && CheckChargeRate(chargeRate));
}
 
int main(){
/* All Temp, SOC & Charge Rate values are inside range */
  assert(batteryIsOk(25, 70, 0.9));
  
  /* Only Temp value outside range */
  assert(!batteryIsOk(50, 70, 0.9));
  
    /* Only SOC value outside range */
  assert(!batteryIsOk(30, 85, 0.9));
  
    /* Only Charge Rate outside range */
  assert(!batteryIsOk(40, 70, 0.7));
  
  /* All Temp, SOC & Charge Rate values are outside range */
  assert(!batteryIsOk(50, 85, 0));
}
