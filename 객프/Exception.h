#pragma once
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

/*����ó�� Ŭ����*/

//��뺸�� ���ұݾ��� ���� �� ȣ��
class InsuffException {
private:
	int fee;
	int money;
public:
	InsuffException(int f, int mon):fee(f),money(mon) {}

	void ShowExceptionInfo() const {
		cout << endl<<"�ݾ��� "<<fee-money<< "�� �����մϴ�." << endl<<endl;
	}
};

//���� �Է� ������ ���� �Է½� ȣ��
class strException {
public:
	void ShowExceptionInfo() const {
		cout << endl<< "���ڸ� �Է��� �ּ���." << endl<<endl;
	}
};

#endif