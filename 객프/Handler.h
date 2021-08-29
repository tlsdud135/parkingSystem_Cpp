#pragma once
#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "Car.h"
#include <vector>
#include<algorithm>
#include<fstream>
#include<string>

//관리 Handler 클래스
class Handler 
{
private:
	vector<shared_ptr<Car>> CarArr;//차 담는 벡터-스마트 포인터 이용
	vector<int> numVec;//iterator 구현 위한 차 수 많큼의 벡터
	vector<int>::iterator it;
	vector<int> sizeVec;//차 종 담은 벡터
	vector<int>feeVec;//비용 담은 벡터
	static int SelecCar;//현재 선택중인 차의 벡터 위치 저장
public:
	void showMenu(void)const;//메뉴
	void CarCount(void);//현재 주차된 차량 수
	void InCar(void);//입장
	void OutCar(void);//퇴장
	void ShowInfo(void);//정보출력
	void Meneger(void);//관리자 메뉴
protected:
	void Small(void);//소형차 입장시
	void Mid(void);//중형차 입장시
	void Large(void);//대형차 입장시
	void Coupon(void);//쿠폰 사용시
	void NCoupon(void);//쿠폰 사용 안할시
	void CouponA(void);//10%쿠폰
	void CouponB(void);//30%쿠폰
	void CouponC(void);//50%쿠폰
	void Delete(void);//관리자 삭제 메뉴
};

//연산자 오버로딩 위한 문자열 클래스
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