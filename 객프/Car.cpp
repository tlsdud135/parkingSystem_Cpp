#include "Car.h"
#include"Common.h"

int Car::count = 0;
//차 생성자
Car::Car(int carSize, string carName)
{
	this->num = ++count;
	this->carSize = carSize;
	this->carName = carName;
	this->inTime = time(NULL);
	outTime = NULL;
	CouFee = NULL;
	fee = NULL;
}

void Car::SetCouFee(int f)
{
	CouFee = f;
}

string Car::GetCarName() const
{
	return carName;
}
int Car::GetFee() {
	return fee;
}
int Car::GetCouFee()
{
	return CouFee;
}
time_t Car::GetOutTime()
{
	return outTime;
}

