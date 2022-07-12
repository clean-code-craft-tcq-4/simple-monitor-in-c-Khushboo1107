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
return ClassifyRange(float temp, 0,45);
}

int CheckStateOfCharge(float soc)
{    
return ClassifyRange(float temp, 20,80);
}

 int CheckChargeRate(float chargeRate)
 {    
return ClassifyRange(float temp, 0,0.8);
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
