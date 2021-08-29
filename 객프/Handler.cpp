#include"Common.h"
#include"Handler.h"
#include"Car.h"
#include"LargeCar.h"
#include"MidCar.h"
#include"SmallCar.h"
#include"Exception.h"
int Handler::SelecCar = 0;

//���θ޴�
void Handler::showMenu(void) const
{
	cout << "-------MENU--------" << endl;
	cout << "0. ���� ������ ���� ��" << endl;//CarCount��
	cout << "1. ����" << endl;//InCar��
	cout << "2. ����" << endl;//OutCar��
	cout << "3. ���� ��ȸ" << endl;//ShowInfo��
	cout << "4. ������" << endl;//Meneger��
	cout << "5. ���α׷� ����" << endl;
}

void Handler::CarCount(void)
{
	int s=0, m=0, l=0;
	cout << "[���� ������ ���� ��]" << endl;
	for (it = numVec.begin(); it != numVec.end(); it++)//���ͷ����� ���
	{
		int i = *it;
		if (CarArr[i]->GetOutTime() == NULL) {//����ð�����(���� ���� ����) �� ī��Ʈ
			if (sizeVec.at(i) == SMALL)//������
				s += 1;
			else if (sizeVec.at(i) == MID)//������
				m += 1;
			else if (sizeVec.at(i) == LARGE)//������
				l += 1;
			else
				cout << "������ ����" << endl;
		}
	}
	cout << "����, ������: " << s << endl;
	cout << "��������, ������: " << m << endl;
	cout << "�ش�����, ������: " << l << endl;
	cout << "�� ���� ��: " << s + m + l << endl << endl;
}

void Handler::InCar(void)
{
	int Size;

	cout << "[�� ���� ����]" << endl;
	cout << "1. ����, ������" << endl;
	cout << "2. ��������, ������" << endl;
	cout << "3. �ش�����, ������" << endl;
	cout << "4. ��������"<<endl;
	while (true) {
		try {
			cout << "����: ";
			cin >> Size;
			if (cin.fail() == true)throw strException();//�����Է½�
			cout << endl;
			if (Size == SMALL) {
				Small();//Small��
				return;
			}
			else if (Size == MID) {
				Mid();//Mid��
				return;
			}
			else if (Size == LARGE) {
				Large();//Large��
				return;
			}
			else if (Size == MAIN)//���θ޴�����
				break;
			else
				cout << "�߸��� ���� ����" << endl<<endl;//�̿��� ���� ���ý�
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void Handler::Small(void)
{
	string Name;

	cout << "[����, ������]" << endl;
	cout << "******��ݾȳ�******" << endl;
	cout << "�⺻���: 500��(10��)"<<endl;
	cout << "�߰����: 200��(10��)" << endl;
	cout << "********************" << endl;
	cout << "�� ��ȣ(��: 12��3456, 0 �Է½� ��������): ";
	cin >> Name;
	cout << endl;
	if (Name == "0") return;//'0'�Է½� ���θ޴���
	else {
		CarArr.push_back(shared_ptr<Car>(new SmallCar(SMALL, Name)));//������ ����, �߰�
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(SMALL);
	}
}

void Handler::Mid(void)
{
	string Name;

	cout << "[��������, ������]" << endl;
	cout << "******��ݾȳ�******" << endl;
	cout << "�⺻���: 750��(20��)" << endl;
	cout << "�߰����: 350��(10��)" << endl;
	cout << "********************" << endl;
	cout << "�� ��ȣ(��: 12��3456, 0 �Է½� ��������): ";
	cin >> Name;
	cout << endl;
	if (Name == "0")return;//'0'�Է½� ���θ޴���
	else {
		CarArr.push_back(shared_ptr<Car>(new MidCar(MID, Name)));//������ ����, �߰�
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(MID);
	}
}

void Handler::Large(void)
{
	string Name;

	cout << "[�ش�����, ������]" << endl;
	cout << "******��ݾȳ�******" << endl;
	cout << "�⺻���: 1000��(30��)" << endl;
	cout << "�߰����: 500��(10��)" << endl;
	cout << "********************" << endl;
	cout << "�� ��ȣ(��: 12��3456, 0 �Է½� ��������): ";//'0'�Է½� ���θ޴���
	cin >> Name;
	cout << endl;
	if (Name == "0") return;
	else {
		CarArr.push_back(shared_ptr<Car>(new LargeCar(LARGE, Name)));//������ ����, �߰�
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(LARGE);
	}
}

void Handler::OutCar(void)
{
	string name;
	int Cou;
	cout << "[��   ��]" << endl;
	cout << "�� ��ȣ(0�Է½� ��������): ";
	cin >> name;
	cout << endl;
	if (name == "0")return;//'0'�Է½� ���θ޴���
	else {
		for (it = numVec.begin(); it != numVec.end(); it++) {
			int i = *it;
			if (CarArr[i]->GetCarName() == name && CarArr[i]->GetOutTime() == NULL) {//�ش� �� ��ȣ�� �ְ�, �����Ǿ� ������(���� ��������)
				SelecCar = i;
				CarArr[i]->Out();//����
				cout << endl;
				cout << "[�� �� ��]" << endl;
				cout << "1.���" << endl;
				cout << "2.����" << endl;
				while (true) {
					try {
						cout << "����: ";
						cin >> Cou;
						if (cin.fail() == true)throw strException();//�����Է½�
						cout << endl;
						if (Cou == YES) {
							Coupon();//Coupon����-���� ������
							return;
						}
						else if (Cou == NO) {
							NCoupon();//NCoupon����-���� ������
							return;
						}
						else
							cout << "�߸��� ���� ����" << endl<<endl;
					}
					catch (strException& expt) {
						expt.ShowExceptionInfo();
						cin.clear();
						cin.ignore(256, '\n');
					}
				}
			}
		}
		cout << "�ش��ϴ� ��ȣ�� ���� �����ϴ�." << endl<<endl;
	}
}

void Handler::Coupon(void)
{
	int number;
	cout << "[���α� ��ȣ �Է�]" << endl;
	while (true) {
		try {
			cout << "�Է�(0�Է½� ���α� ���� ����): ";
			cin >> number;
			if (cin.fail() == true)throw strException();//�����Է½�
			cout << endl;
			if (number == 0) {//'0'�Է½� NCoupon����-����������
				NCoupon();
				return;
			}
			else if (number == A) {//�Է��� ������ȣ�� ��ġ�� ��-1111
				CouponA();//CouponA��(10%��������)
				return;
			}
			else if (number == B) {//�Է��� ������ȣ�� ��ġ�� ��-2222
				CouponB();//CouponB��(30%��������)
				return;
			}
			else if (number == C) {//�Է��� ������ȣ�� ��ġ�� ��-3333
				CouponC();//CouponC��(50%��������)
				return;
			}
			else
				cout << "�������� �ʴ� �����Դϴ�." << endl<<endl;
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void Handler::CouponA(void)
{
	int money;
	int f = (int)((CarArr[SelecCar]->GetFee()) / 100 * 90);
	CarArr[SelecCar]->SetCouFee(f);//���� ���� ��� ����
	cout << "[10% ���α� ����]" << endl;
	cout << "���: " << f<<endl;
	while(true){
		try {
			cout << "�Աݾ�: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//�����Է½�
			try {
				if (money < f)throw InsuffException(f, money);//����� ���ұݾ׺��� Ŭ ��
				else {
					cout << "�Ž�����: " << money - f << endl;
					cout << "�̿��� �ּż� �����մϴ�." << endl << endl;
					break;
				}
			}
			catch (InsuffException& expt) {
				expt.ShowExceptionInfo();
			}
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void Handler::CouponB(void)
{
	int money;
	int f= (int)((CarArr[SelecCar]->GetFee()) / 100 * 70);
	CarArr[SelecCar]->SetCouFee(f);//���� ���� ��� ����
	cout << "[30% ���α� ����]" << endl;
	cout << "���: " << f << endl;
	while (true) {
		try {
			cout << "�Աݾ�: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//�����Է½�
			try {
				if (money < f)throw InsuffException(f, money);//����� ���ұݾ׺��� Ŭ ��
				else {
					cout << "�Ž�����: " << money - f << endl;
					cout << "�̿��� �ּż� �����մϴ�." << endl << endl;
					break;
				}
			}
			catch (InsuffException& expt) {
				expt.ShowExceptionInfo();
			}
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void Handler::CouponC(void)
{
	int money;
	int f = (int)((CarArr[SelecCar]->GetFee()) / 100 * 50);
	CarArr[SelecCar]->SetCouFee(f);//���� ���� ��� ����
	cout << "[50% ���α� ����]" << endl;
	cout << "���: " << f << endl;
	while (true) {
		try {
			cout << "�Աݾ�: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//�����Է½�
			try {
				if (money < f)throw InsuffException(f, money);//����� ���ұݾ׺��� Ŭ ��
				else {
					cout << "�Ž�����: " << money - f << endl;
					cout << "�̿��� �ּż� �����մϴ�." << endl << endl;
					break;
				}
			}
			catch (InsuffException& expt) {
				expt.ShowExceptionInfo();
			}
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void Handler::NCoupon(void)
{
	int money;
	cout << "[��� ���]" << endl;
	cout << "���: "<<CarArr[SelecCar]->GetFee()<<endl;
	while (true) {
		try {
			cout << "�Աݾ�: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//�����Է½�
			try {
				if (money < CarArr[SelecCar]->GetFee())throw InsuffException(CarArr[SelecCar]->GetFee(), money);//����� ���ұݾ׺��� Ŭ ��
				else {
					cout << "�Ž�����: " << money - CarArr[SelecCar]->GetFee() << endl;
					cout << "�̿��� �ּż� �����մϴ�." << endl << endl;
					break;
				}
			}
			catch (InsuffException& expt) {
				expt.ShowExceptionInfo();
			}
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	
}

void Handler::ShowInfo(void)
{
	string name;
	bool b=false;
	cout << "[��   ȸ]" << endl;
	cout << "�� ��ȣ: ";
	cin >> name;
	cout << endl;
	//name�� ���� �� ��ȣ�� �� ���� ��ȸ
	for (it=numVec.begin(); it!=numVec.end(); it++)
	{
		int i = *it;
		if (CarArr[i]->GetCarName() == name) {
			b = true;
			CarArr[i]->ShowCarInfo();
			cout << endl;
		}
	}
	if(b==false)
		cout<<"�ش��ϴ� ��ȣ�� ���� �����ϴ�." << endl << endl;
}

void Handler::Meneger(void)
{
	string s;
	int n;
	int AddMoney=0;
	cout << "[������ ��ȸ]" << endl;
	try {
		cout << "��й�ȣ �Է�: ";//1234
		cin >> n;
		if (cin.fail() == true)throw strException();//�����Է½�
		cout << endl;
		if (n == 1234) {
			if (CarArr.size() == 0)//������ ��� �̷��� ���� ��
				cout << "�̿��� ����" << endl << endl;
			else {
				for (it = numVec.begin(); it != numVec.end(); it++)
				{
					int i = *it;
					if (CarArr[i]->GetCouFee() != NULL) {//���� ����� �� �϶�
						AddMoney += CarArr[i]->GetCouFee();//���� ��밪 ���ϱ�
						feeVec.push_back(CarArr[i]->GetCouFee());
					}
					else {
						AddMoney += CarArr[i]->GetFee();//��� ���ϱ�
						feeVec.push_back(CarArr[i]->GetFee());
					}

					CarArr[i]->ShowCarInfo();//��ü ���� ��ȸ
					cout << endl;
				}
				cout << "������ ��: " << count(sizeVec.begin(), sizeVec.end(), 1) << endl;//��� �� ������ ��-STL�˰��� ���
				cout << "������ ��: " << count(sizeVec.begin(), sizeVec.end(), 2) << endl;//��� �� ������ ��-STL�˰��� ���
				cout << "������ ��: " << count(sizeVec.begin(), sizeVec.end(), 3) << endl;//��� �� ������ ��-STL�˰��� ���
				cout << "����� 3000�� �̻��� �� ��: " << count_if(feeVec.begin(), feeVec.end(), [](int e) {return e >= 3000; }) << endl;//��� �� ���Һ���� 3000�̻��� �� ��-STL�˰��� ���
				cout << "�� �մ� ��: " << CarArr.size() << endl << "�� ����: " << AddMoney << endl << endl;//�� ��� ��, �� ����
				str string("�� �մ� ��: ");
				string + CarArr.size();//������ �����ε� ���
				string - "\n�� ����: ";//������ �����ε� ���
				string + AddMoney;//������ �����ε� ���
				ofstream writeFile;//���� �����
				writeFile.open("test.txt");//������ ����
				writeFile.write(string.GetS().c_str(), string.GetS().size());//str�� string ���� test.txt�� ����(�� �մ� ���� �� ���� ����)
				writeFile.close();

				cout << "'����' �Է½� ��� ���� �������� �Ѿ�ϴ�(�ٸ� �Է½� ��������): ";
				cin >> s;
				cout << endl;
				if (s == "����") {
					Delete();//'����'�Է½� Delete��
				}
				else
					cout << "�������� �̵��մϴ�." << endl << endl;
			}

		}
		else
			cout << "��й�ȣ ����!" << endl << endl;
	}
	catch (strException& expt) {
		expt.ShowExceptionInfo();
		cin.clear();
		cin.ignore(256, '\n');
	}

}

void Handler::Delete(void)
{
	int n;
	cout << "[��   ��]" << endl;
	while (true) {
		try {
			cout << "������ ���� ���° ����� �����Ͻðڽ��ϱ�(0���ý� �������� -1�Է½� ��ü����): ";
			cin >> n;
			if(cin.fail() == true)throw strException();//�����Է½�
			cout << endl;
			if (CarArr.size() >= n && n > 0) {
				CarArr.erase(CarArr.begin() + n - 1);//ù��° ����� �������� n��°�� ����� ����
				numVec.pop_back();
				sizeVec.erase(sizeVec.begin() + n - 1);
				feeVec.erase(feeVec.begin() + n - 1);
				cout << n << "��° ����� �����Ǿ����ϴ�." << endl << endl;
				break;
			}
			else if (n == 0)//���θ޴���
				break;
			else if (n == -1) {//'-1'�Է½� ��� ��ü ����
				CarArr.clear();
				numVec.clear();
				sizeVec.clear();
				feeVec.clear();
				cout << "��� ����� �����Ǿ����ϴ�." << endl << endl;
				break;
			}
			else
				cout << "������ ��� �Է��Դϴ�." << endl << endl;//��� ���� ���� ���� ���� �Է½�
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}