#include"Common.h"
#include"Handler.h"
#include"Car.h"
#include"LargeCar.h"
#include"MidCar.h"
#include"SmallCar.h"
#include"Exception.h"
int Handler::SelecCar = 0;

//메인메뉴
void Handler::showMenu(void) const
{
	cout << "-------MENU--------" << endl;
	cout << "0. 현재 주차된 차량 수" << endl;//CarCount로
	cout << "1. 입장" << endl;//InCar로
	cout << "2. 퇴장" << endl;//OutCar로
	cout << "3. 정보 조회" << endl;//ShowInfo로
	cout << "4. 관리자" << endl;//Meneger로
	cout << "5. 프로그램 종료" << endl;
}

void Handler::CarCount(void)
{
	int s=0, m=0, l=0;
	cout << "[현재 주차된 차량 수]" << endl;
	for (it = numVec.begin(); it != numVec.end(); it++)//이터레이터 사용
	{
		int i = *it;
		if (CarArr[i]->GetOutTime() == NULL) {//퇴장시간없는(아직 퇴장 안한) 차 카운트
			if (sizeVec.at(i) == SMALL)//소형차
				s += 1;
			else if (sizeVec.at(i) == MID)//중형차
				m += 1;
			else if (sizeVec.at(i) == LARGE)//대형차
				l += 1;
			else
				cout << "사이즈 오류" << endl;
		}
	}
	cout << "경차, 소형차: " << s << endl;
	cout << "준중형차, 중형차: " << m << endl;
	cout << "준대형차, 대형차: " << l << endl;
	cout << "총 차량 수: " << s + m + l << endl << endl;
}

void Handler::InCar(void)
{
	int Size;

	cout << "[차 종류 선택]" << endl;
	cout << "1. 경차, 소형차" << endl;
	cout << "2. 준중형차, 중형차" << endl;
	cout << "3. 준대형차, 대형차" << endl;
	cout << "4. 메인으로"<<endl;
	while (true) {
		try {
			cout << "선택: ";
			cin >> Size;
			if (cin.fail() == true)throw strException();//문자입력시
			cout << endl;
			if (Size == SMALL) {
				Small();//Small로
				return;
			}
			else if (Size == MID) {
				Mid();//Mid로
				return;
			}
			else if (Size == LARGE) {
				Large();//Large로
				return;
			}
			else if (Size == MAIN)//메인메뉴으로
				break;
			else
				cout << "잘못된 숫자 선택" << endl<<endl;//이외의 숫자 선택시
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

	cout << "[경차, 소형차]" << endl;
	cout << "******요금안내******" << endl;
	cout << "기본요금: 500원(10분)"<<endl;
	cout << "추가요금: 200원(10분)" << endl;
	cout << "********************" << endl;
	cout << "차 번호(예: 12가3456, 0 입력시 메인으로): ";
	cin >> Name;
	cout << endl;
	if (Name == "0") return;//'0'입력시 메인메뉴로
	else {
		CarArr.push_back(shared_ptr<Car>(new SmallCar(SMALL, Name)));//소형차 생성, 추가
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(SMALL);
	}
}

void Handler::Mid(void)
{
	string Name;

	cout << "[준중형차, 중형차]" << endl;
	cout << "******요금안내******" << endl;
	cout << "기본요금: 750원(20분)" << endl;
	cout << "추가요금: 350원(10분)" << endl;
	cout << "********************" << endl;
	cout << "차 번호(예: 12가3456, 0 입력시 메인으로): ";
	cin >> Name;
	cout << endl;
	if (Name == "0")return;//'0'입력시 메인메뉴로
	else {
		CarArr.push_back(shared_ptr<Car>(new MidCar(MID, Name)));//중형차 생성, 추가
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(MID);
	}
}

void Handler::Large(void)
{
	string Name;

	cout << "[준대형차, 대형차]" << endl;
	cout << "******요금안내******" << endl;
	cout << "기본요금: 1000원(30분)" << endl;
	cout << "추가요금: 500원(10분)" << endl;
	cout << "********************" << endl;
	cout << "차 번호(예: 12가3456, 0 입력시 메인으로): ";//'0'입력시 메인메뉴로
	cin >> Name;
	cout << endl;
	if (Name == "0") return;
	else {
		CarArr.push_back(shared_ptr<Car>(new LargeCar(LARGE, Name)));//대형차 생성, 추가
		numVec.push_back(CarArr.size() - 1);
		sizeVec.push_back(LARGE);
	}
}

void Handler::OutCar(void)
{
	string name;
	int Cou;
	cout << "[퇴   장]" << endl;
	cout << "차 번호(0입력시 메인으로): ";
	cin >> name;
	cout << endl;
	if (name == "0")return;//'0'입력시 메인메뉴로
	else {
		for (it = numVec.begin(); it != numVec.end(); it++) {
			int i = *it;
			if (CarArr[i]->GetCarName() == name && CarArr[i]->GetOutTime() == NULL) {//해당 차 번호가 있고, 주차되어 있으면(퇴장 안했으면)
				SelecCar = i;
				CarArr[i]->Out();//퇴장
				cout << endl;
				cout << "[할 인 권]" << endl;
				cout << "1.등록" << endl;
				cout << "2.없음" << endl;
				while (true) {
					try {
						cout << "선택: ";
						cin >> Cou;
						if (cin.fail() == true)throw strException();//문자입력시
						cout << endl;
						if (Cou == YES) {
							Coupon();//Coupon으로-쿠폰 있을시
							return;
						}
						else if (Cou == NO) {
							NCoupon();//NCoupon으로-쿠폰 없을시
							return;
						}
						else
							cout << "잘못된 숫자 선택" << endl<<endl;
					}
					catch (strException& expt) {
						expt.ShowExceptionInfo();
						cin.clear();
						cin.ignore(256, '\n');
					}
				}
			}
		}
		cout << "해당하는 번호의 차는 없습니다." << endl<<endl;
	}
}

void Handler::Coupon(void)
{
	int number;
	cout << "[할인권 번호 입력]" << endl;
	while (true) {
		try {
			cout << "입력(0입력시 할인권 없이 진행): ";
			cin >> number;
			if (cin.fail() == true)throw strException();//문자입력시
			cout << endl;
			if (number == 0) {//'0'입력시 NCoupon으로-쿠폰없을시
				NCoupon();
				return;
			}
			else if (number == A) {//입력한 쿠폰번호가 일치할 때-1111
				CouponA();//CouponA로(10%할인쿠폰)
				return;
			}
			else if (number == B) {//입력한 쿠폰번호가 일치할 때-2222
				CouponB();//CouponB로(30%할인쿠폰)
				return;
			}
			else if (number == C) {//입력한 쿠폰번호가 일치할 때-3333
				CouponC();//CouponC로(50%할인쿠폰)
				return;
			}
			else
				cout << "존재하지 않는 쿠폰입니다." << endl<<endl;
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
	CarArr[SelecCar]->SetCouFee(f);//쿠폰 적용 요금 설정
	cout << "[10% 할인권 적용]" << endl;
	cout << "요금: " << f<<endl;
	while(true){
		try {
			cout << "입금액: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//문자입력시
			try {
				if (money < f)throw InsuffException(f, money);//비용이 지불금액보다 클 시
				else {
					cout << "거스름돈: " << money - f << endl;
					cout << "이용해 주셔서 감사합니다." << endl << endl;
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
	CarArr[SelecCar]->SetCouFee(f);//쿠폰 적용 요금 설정
	cout << "[30% 할인권 적용]" << endl;
	cout << "요금: " << f << endl;
	while (true) {
		try {
			cout << "입금액: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//문자입력시
			try {
				if (money < f)throw InsuffException(f, money);//비용이 지불금액보다 클 시
				else {
					cout << "거스름돈: " << money - f << endl;
					cout << "이용해 주셔서 감사합니다." << endl << endl;
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
	CarArr[SelecCar]->SetCouFee(f);//쿠폰 적용 요금 설정
	cout << "[50% 할인권 적용]" << endl;
	cout << "요금: " << f << endl;
	while (true) {
		try {
			cout << "입금액: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//문자입력시
			try {
				if (money < f)throw InsuffException(f, money);//비용이 지불금액보다 클 시
				else {
					cout << "거스름돈: " << money - f << endl;
					cout << "이용해 주셔서 감사합니다." << endl << endl;
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
	cout << "[요금 계산]" << endl;
	cout << "요금: "<<CarArr[SelecCar]->GetFee()<<endl;
	while (true) {
		try {
			cout << "입금액: ";
			cin >> money;
			if (cin.fail() == true)throw strException();//문자입력시
			try {
				if (money < CarArr[SelecCar]->GetFee())throw InsuffException(CarArr[SelecCar]->GetFee(), money);//비용이 지불금액보다 클 시
				else {
					cout << "거스름돈: " << money - CarArr[SelecCar]->GetFee() << endl;
					cout << "이용해 주셔서 감사합니다." << endl << endl;
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
	cout << "[조   회]" << endl;
	cout << "차 번호: ";
	cin >> name;
	cout << endl;
	//name과 같은 차 번호의 차 정보 조회
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
		cout<<"해당하는 번호의 차는 없습니다." << endl << endl;
}

void Handler::Meneger(void)
{
	string s;
	int n;
	int AddMoney=0;
	cout << "[관리자 조회]" << endl;
	try {
		cout << "비밀번호 입력: ";//1234
		cin >> n;
		if (cin.fail() == true)throw strException();//문자입력시
		cout << endl;
		if (n == 1234) {
			if (CarArr.size() == 0)//주차장 사용 이력이 없을 때
				cout << "이용자 없음" << endl << endl;
			else {
				for (it = numVec.begin(); it != numVec.end(); it++)
				{
					int i = *it;
					if (CarArr[i]->GetCouFee() != NULL) {//쿠폰 사용한 차 일때
						AddMoney += CarArr[i]->GetCouFee();//쿠폰 사용값 더하기
						feeVec.push_back(CarArr[i]->GetCouFee());
					}
					else {
						AddMoney += CarArr[i]->GetFee();//비용 더하기
						feeVec.push_back(CarArr[i]->GetFee());
					}

					CarArr[i]->ShowCarInfo();//전체 내용 조회
					cout << endl;
				}
				cout << "소형차 수: " << count(sizeVec.begin(), sizeVec.end(), 1) << endl;//기록 중 소형차 수-STL알고리즘 사용
				cout << "중형차 수: " << count(sizeVec.begin(), sizeVec.end(), 2) << endl;//기록 중 중형차 수-STL알고리즘 사용
				cout << "대형차 수: " << count(sizeVec.begin(), sizeVec.end(), 3) << endl;//기록 중 대형차 수-STL알고리즘 사용
				cout << "요금이 3000원 이상인 차 수: " << count_if(feeVec.begin(), feeVec.end(), [](int e) {return e >= 3000; }) << endl;//기록 중 지불비용이 3000이상인 차 수-STL알고리즘 사용
				cout << "총 손님 수: " << CarArr.size() << endl << "총 수익: " << AddMoney << endl << endl;//총 기록 수, 총 수익
				str string("총 손님 수: ");
				string + CarArr.size();//연산자 오버로딩 사용
				string - "\n총 수익: ";//연산자 오버로딩 사용
				string + AddMoney;//연산자 오버로딩 사용
				ofstream writeFile;//파일 입출력
				writeFile.open("test.txt");//없으면 생성
				writeFile.write(string.GetS().c_str(), string.GetS().size());//str의 string 내용 test.txt에 저장(총 손님 수와 총 수익 저장)
				writeFile.close();

				cout << "'삭제' 입력시 기록 삭제 페이지로 넘어갑니다(다른 입력시 메인으로): ";
				cin >> s;
				cout << endl;
				if (s == "삭제") {
					Delete();//'삭제'입력시 Delete로
				}
				else
					cout << "메인으로 이동합니다." << endl << endl;
			}

		}
		else
			cout << "비밀번호 오류!" << endl << endl;
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
	cout << "[삭   제]" << endl;
	while (true) {
		try {
			cout << "위에서 부터 몇번째 기록을 삭제하시겠습니까(0선택시 메인으로 -1입력시 전체삭제): ";
			cin >> n;
			if(cin.fail() == true)throw strException();//문자입력시
			cout << endl;
			if (CarArr.size() >= n && n > 0) {
				CarArr.erase(CarArr.begin() + n - 1);//첫번째 기록을 기준으로 n번째인 기록이 삭제
				numVec.pop_back();
				sizeVec.erase(sizeVec.begin() + n - 1);
				feeVec.erase(feeVec.begin() + n - 1);
				cout << n << "번째 기록이 삭제되었습니다." << endl << endl;
				break;
			}
			else if (n == 0)//메인메뉴로
				break;
			else if (n == -1) {//'-1'입력시 기록 전체 삭제
				CarArr.clear();
				numVec.clear();
				sizeVec.clear();
				feeVec.clear();
				cout << "모든 기록이 삭제되었습니다." << endl << endl;
				break;
			}
			else
				cout << "범위를 벗어난 입력입니다." << endl << endl;//기록 수와 맞지 않은 숫자 입력시
		}
		catch (strException& expt) {
			expt.ShowExceptionInfo();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}