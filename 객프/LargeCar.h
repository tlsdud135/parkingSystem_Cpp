#pragma once
#ifndef __LARGE_CAR_H__
#define __LARGE_CAR_H__

#include "Car.h"
//추상클래스 상속하는 클래스
class LargeCar :public Car
{
private:
	const int BasicRate = 1000;//기본요금(30분(초)간)
	const int Extra = 500;//추가요금(10분(초)마다)
	void timeCalc() {
		this->outTime = time(NULL);
		t = (int)(outTime - inTime);
		t = t / 10;//실행 시간상 임의로 10분을 10초로 설정
	}
public:
	LargeCar(int carSize, string carName) :Car(carSize, carName) {}
	virtual void Out()
	{
		timeCalc();//시간 계산

		if (t <= 2)
			fee = BasicRate;
		else
			fee = BasicRate + Extra * (t - 2);
		ShowCarInfo();
	}

	virtual void ShowCarInfo() {
		//출력 시간 설정
		struct tm pTimeInfo;
		localtime_s(&pTimeInfo, &inTime);
		int month = pTimeInfo.tm_mon + 1;
		int day = pTimeInfo.tm_mday;
		int hour = pTimeInfo.tm_hour;
		int min = pTimeInfo.tm_min;
		int sec = pTimeInfo.tm_sec;

		cout << "입장번호: " << num << endl;
		cout << "차 번호: " << carName << endl;
		cout << "차 종: " << "준대형차, 대형차" << endl;//대형차 클래스이므로
		cout << "입장시간: " << month << "월 " << day << "일 " << hour << "시 " << min << "분 " << sec << "초" << endl;
		if (outTime != NULL) {//차가 주차장을 나갔을 경우 조회시 퇴장시간 보임
			//출력시간을 퇴장시간으로
			localtime_s(&pTimeInfo, &outTime);
			month = pTimeInfo.tm_mon + 1;
			day = pTimeInfo.tm_mday;
			hour = pTimeInfo.tm_hour;
			min = pTimeInfo.tm_min;
			sec = pTimeInfo.tm_sec;
			cout << "퇴장시간: " << month << "월 " << day << "일 " << hour << "시 " << min << "분 " << sec << "초" << endl;
		}
		else
			cout << "퇴장시간: " << endl;
		if (fee != NULL) {//차가 주차장을 나갔을 경우 조회시 요금 보임
			cout << "요금: " << fee << endl;
		}
		else
			cout << "요금: " << endl;
		if (CouFee != NULL) {//쿠폰을 적용했을 경우 쿠폰적용요금 보임
			cout << "쿠폰 적용 요금: " << CouFee << endl;
		}
	}
};

#endif