#include"Common.h"
#include"Handler.h"
#include"Exception.h"

int main(void)
{
	Handler handler;
	int choice;

	//Ÿ��Ʋ ���
	cout << "====================" << endl;
	cout << "=  DS Parking Lot  =" << endl;
	cout << "====================" << endl;

	while (true) {
		handler.showMenu();//���θ޴�
		try {
			cout << "����: ";
			cin >> choice;
			if (cin.fail() == true)throw strException();//�����Է½�
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
				cout << "�߸��� ���� ����" << endl<<endl;
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