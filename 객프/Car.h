#pragma once
#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <time.h>
using namespace std;
//추상클래스
class Car{
private:
	static int count;//클래스 변수-고유번호 부여
	int carSize;//차 종(크기)
protected:
	int num;//고유번호
	string carName;//문자열 변수-차 번호
	time_t inTime;//차가 들어온 시간
	time_t outTime;//차가 나간 시간
	int CouFee;//쿠폰적용비용
	int fee;//비용
	int t;//차가 주차장에 머문 시간
public:
	Car(int carSize, string carName);
	void SetCouFee(int f);
	virtual void Out()=0;//순수 가상 함수-주차장에서 차 나감
	int GetFee();
	int GetCouFee();
	time_t GetOutTime();
	string GetCarName() const;
	virtual void ShowCarInfo()=0;//순수 가상 함수-정보출력(입장번호(고유번호),차번호,차종,입장시간,퇴장시간,요금,쿠폰적용요금)
	
};

#endif