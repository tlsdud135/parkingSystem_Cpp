#pragma once
#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <time.h>
using namespace std;
//�߻�Ŭ����
class Car{
private:
	static int count;//Ŭ���� ����-������ȣ �ο�
	int carSize;//�� ��(ũ��)
protected:
	int num;//������ȣ
	string carName;//���ڿ� ����-�� ��ȣ
	time_t inTime;//���� ���� �ð�
	time_t outTime;//���� ���� �ð�
	int CouFee;//����������
	int fee;//���
	int t;//���� �����忡 �ӹ� �ð�
public:
	Car(int carSize, string carName);
	void SetCouFee(int f);
	virtual void Out()=0;//���� ���� �Լ�-�����忡�� �� ����
	int GetFee();
	int GetCouFee();
	time_t GetOutTime();
	string GetCarName() const;
	virtual void ShowCarInfo()=0;//���� ���� �Լ�-�������(�����ȣ(������ȣ),����ȣ,����,����ð�,����ð�,���,����������)
	
};

#endif