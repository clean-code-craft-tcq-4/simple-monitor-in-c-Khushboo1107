
#define E_OK 1
#define E_NOT_OK 0

int ClassifyRange(float CurrentValue, int MinRange, int MaxRange);
int ClassifyTemperature(float temperature);
int CheckStateOfCharge(float soc);
int CheckChargeRate(float chargeRate);

