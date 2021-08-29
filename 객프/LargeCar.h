#pragma once
#ifndef __LARGE_CAR_H__
#define __LARGE_CAR_H__

#include "Car.h"
//�߻�Ŭ���� ����ϴ� Ŭ����
class LargeCar :public Car
{
private:
	const int BasicRate = 1000;//�⺻���(30��(��)��)
	const int Extra = 500;//�߰����(10��(��)����)
	void timeCalc() {
		this->outTime = time(NULL);
		t = (int)(outTime - inTime);
		t = t / 10;//���� �ð��� ���Ƿ� 10���� 10�ʷ� ����
	}
public:
	LargeCar(int carSize, string carName) :Car(carSize, carName) {}
	virtual void Out()
	{
		timeCalc();//�ð� ���

		if (t <= 2)
			fee = BasicRate;
		else
			fee = BasicRate + Extra * (t - 2);
		ShowCarInfo();
	}

	virtual void ShowCarInfo() {
		//��� �ð� ����
		struct tm pTimeInfo;
		localtime_s(&pTimeInfo, &inTime);
		int month = pTimeInfo.tm_mon + 1;
		int day = pTimeInfo.tm_mday;
		int hour = pTimeInfo.tm_hour;
		int min = pTimeInfo.tm_min;
		int sec = pTimeInfo.tm_sec;

		cout << "�����ȣ: " << num << endl;
		cout << "�� ��ȣ: " << carName << endl;
		cout << "�� ��: " << "�ش�����, ������" << endl;//������ Ŭ�����̹Ƿ�
		cout << "����ð�: " << month << "�� " << day << "�� " << hour << "�� " << min << "�� " << sec << "��" << endl;
		if (outTime != NULL) {//���� �������� ������ ��� ��ȸ�� ����ð� ����
			//��½ð��� ����ð�����
			localtime_s(&pTimeInfo, &outTime);
			month = pTimeInfo.tm_mon + 1;
			day = pTimeInfo.tm_mday;
			hour = pTimeInfo.tm_hour;
			min = pTimeInfo.tm_min;
			sec = pTimeInfo.tm_sec;
			cout << "����ð�: " << month << "�� " << day << "�� " << hour << "�� " << min << "�� " << sec << "��" << endl;
		}
		else
			cout << "����ð�: " << endl;
		if (fee != NULL) {//���� �������� ������ ��� ��ȸ�� ��� ����
			cout << "���: " << fee << endl;
		}
		else
			cout << "���: " << endl;
		if (CouFee != NULL) {//������ �������� ��� ���������� ����
			cout << "���� ���� ���: " << CouFee << endl;
		}
	}
};

#endif