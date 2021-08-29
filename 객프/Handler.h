#pragma once
#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Car.h"
#include <vector>
#include<algorithm>
#include<fstream>
#include<string>

//���� Handler Ŭ����
class Handler 
{
private:
	vector<shared_ptr<Car>> CarArr;//�� ��� ����-����Ʈ ������ �̿�
	vector<int> numVec;//iterator ���� ���� �� �� ��ŭ�� ����
	vector<int>::iterator it;
	vector<int> sizeVec;//�� �� ���� ����
	vector<int>feeVec;//��� ���� ����
	static int SelecCar;//���� �������� ���� ���� ��ġ ����
public:
	void showMenu(void)const;//�޴�
	void CarCount(void);//���� ������ ���� ��
	void InCar(void);//����
	void OutCar(void);//����
	void ShowInfo(void);//�������
	void Meneger(void);//������ �޴�
protected:
	void Small(void);//������ �����
	void Mid(void);//������ �����
	void Large(void);//������ �����
	void Coupon(void);//���� ����
	void NCoupon(void);//���� ��� ���ҽ�
	void CouponA(void);//10%����
	void CouponB(void);//30%����
	void CouponC(void);//50%����
	void Delete(void);//������ ���� �޴�
};

//������ �����ε� ���� ���ڿ� Ŭ����
class str
{
	string s;
public:
	str(string s) {
		this->s = s;
	}
	void operator+(int op) {
		s.append(to_string(op));
	}
	void operator-(string op2) {
		s.append(op2);
	}
	string GetS() {
		return s;
	}
};

#endif