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
return ClassifyRange(chargeRate, 0, 0.8);
}
  
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
 return (ClassifyTemperature(temperature) && CheckStateOfCharge(soc) && CheckChargeRate(chargeRate));
}
 

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
