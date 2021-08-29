#pragma once
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

/*예외처리 클래스*/

//비용보다 지불금액이 적을 때 호출
class InsuffException {
private:
	int fee;
	int money;
public:
	InsuffException(int f, int mon):fee(f),money(mon) {}

	void ShowExceptionInfo() const {
		cout << endl<<"금액이 "<<fee-money<< "원 부족합니다." << endl<<endl;
	}
};

//숫자 입력 구간에 문자 입력시 호출
class strException {
public:
	void ShowExceptionInfo() const {
		cout << endl<< "숫자만 입력해 주세요." << endl<<endl;
	}
};

#endif