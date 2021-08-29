#include"Common.h"
#include"Handler.h"
#include"Exception.h"

int main(void)
{
	Handler handler;
	int choice;

	//타이틀 출력
	cout << "====================" << endl;
	cout << "=  DS Parking Lot  =" << endl;
	cout << "====================" << endl;

	while (true) {
		handler.showMenu();//메인메뉴
		try {
			cout << "선택: ";
			cin >> choice;
			if (cin.fail() == true)throw strException();//문자입력시
			cout << endl;

			switch (choice)
			{
			case COUNT:
				handler.CarCount();
				break;
			case IN:
				handler.InCar();
				break;
			case OUT:
				handler.OutCar();
				break;
			case INFO:
				handler.ShowInfo();
				break;
			case MENEGER:
				handler.Meneger();
				break;
			case EXIT:
				return 0;
			default:
				cout << "잘못된 숫자 선택" << endl<<endl;
			}
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	return 0;
}