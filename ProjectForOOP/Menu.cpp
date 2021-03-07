#include "Menu.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include "HostelResident.h"
#include "FileWorker.h"
#include "Administrator.h"
using namespace std;

void Menu::runMemberMenu()
{
	setlocale(0, "");

	string userFileName, residentsFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� residents.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	residentsFileName = residentsFileName.empty() ? "residents.txt" : residentsFileName;
	
	vector<HostelResident> residents = FileWorker::getResidentsFromFile(residentsFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. �������� ���� ������" << endl;
		cout << "2. ����� �� �.�.�." << endl;
		cout << "3. ����������" << endl;
		cout << "4. ������ �������������� �������" << endl;
		cout << "5. ������ �������������� �������" << endl;
		cout << "6. �����" << endl;
		int choose = HelpFunctions::getNumber();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			HostelResident::printAsTable(residents);
		}
		break;
		case 2:
		{
			cout << "������� ��� ��� ������: " << endl;
			string name;
			getline(cin, name);
			HostelResident::findByFIO(residents, name);
		}
		break;
		case 3:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "���� ������������:" << endl;
				cout << "1. �� �����" << endl;
				cout << "2. �� ���� ���������" << endl;
				cout << "3. �� ���� ���������" << endl;
				cout << "4. �����" << endl;
				int SubChoose = HelpFunctions::getNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
					cout << "�������������� �� �����;" << endl;
					HostelResident::SortByFunc(residents, [](HostelResident memberFirst, HostelResident memberSecond) {return memberFirst.getFullName() < memberSecond.getFullName(); });
					HostelResident::printAsTable(residents);
					break;
				case 2:
					cout << "�������������� �� ���� ���������;" << endl;
					HostelResident::SortByFunc(residents, [](HostelResident hostelResidentFirst, HostelResident hostelResidentsecond) {return hostelResidentFirst.getSettlementYear() < hostelResidentsecond.getSettlementYear(); });
					HostelResident::printAsTable(residents);
					break;
				case 3:
					cout << "�������������� �� ���� ���������;" << endl;
					HostelResident::SortByFunc(residents, [](HostelResident hostelResidentFirst, HostelResident hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
					HostelResident::printAsTable(residents);
					break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 4:
		{
			cout << "������� ���:" << endl;
			int year = HelpFunctions::getNumber();
			cout << "������ �������������� �������:" << endl << endl;
			HostelResident::sortByFIOAfterYear(residents, year);
		}
		break;
		case 5:
		{
			cout << "������ �������������� �������:" << endl << endl;
			HostelResident::whoLiveNow(residents);
		}
		break;
		case 6:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� - ���!" << endl;
			break;

		}
		system("pause");
	}
}

void Menu::runAdminMenu()
{
	setlocale(0, "");
	string userFileName, residentsFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� users.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	userFileName = userFileName.empty() ? "users.txt" : userFileName;
	cout << "������� ��� �����, ��� �������������� ��������� (�� ��������� residents.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, residentsFileName);
	residentsFileName = residentsFileName.empty() ? "members.txt" : residentsFileName;

	Administrator admin(userFileName, residentsFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. ���������� �������� �������� ������������:" << endl;
		cout << "2. ������ � ������ ������:" << endl;
		cout << "3. ������ � �������:" << endl;
		cout << "4. �����" << endl;
		int choose = HelpFunctions::getNumber();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "���������� �������� �������� ������������:" << endl;
				cout << "1. ����������� ��� ������� ������" << endl;
				cout << "2. �������� ������� ������" << endl;
				cout << "3. ��������������� ������� ������" << endl;
				cout << "4. ������� ������� ������" << endl;
				cout << "5. �����" << endl;
				int SubChoose = HelpFunctions::getNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.viewUsers();
				}
				break;
				case 2:
				{
					User user;
					user.input();
					admin.appendUser(user);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = HelpFunctions::getNumber() - 1;
					admin.editUser(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = HelpFunctions::getNumber() - 1;
					admin.deleteUser(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 2:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "������ � �������:" << endl;
				cout << "1. ������� ����" << endl;
				cout << "2. ������� ����" << endl;
				cout << "3. ������� ����" << endl;
				cout << "4. �����" << endl;
				int SubChoose = HelpFunctions::getNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.createFile(fileName);
				}
				break;
				case 2:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.openFile(fileName);
				}
				break;
				case 3:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.removeFile(fileName);
				}
				break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 3:
		{
			bool exitSubMenu = true;
			while (exitSubMenu)
			{
				system("cls");
				cout << "������ � �������: " << endl;
				cout << "1. �������� ���� ������" << endl;
				cout << "2. �������� ������" << endl;
				cout << "3. ������� ������" << endl;
				cout << "4. ������������� ������" << endl;
				cout << "5. �����" << endl;
				int SubChoose = HelpFunctions::getNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.viewResidents();
				}
				break;
				case 2:
				{
					HostelResident resident;
					resident.Input();
					admin.appendResidents(resident);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = HelpFunctions::getNumber() - 1;
					admin.deleteResidents(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = HelpFunctions::getNumber() - 1;
					admin.editResidents(number);
				}
				break;
				case 5:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}
				system("pause");
			}
		}
		break;
		case 4:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� - ���!" << endl;
			break;

		}
		system("pause");
	}
}

void Menu::firstMenu()
{
	setlocale(0, "");
	bool exitMenu = true;
	while (exitMenu)
	{
		cout << "�������� ����:" << endl;
		cout << "1. ������������" << endl;
		cout << "2. �������������" << endl;
		cout << "3. �����" << endl;
		int menuChoose = HelpFunctions::getNumber();
		system("cls");
		switch (menuChoose)
		{
		case 1:
			runMemberMenu();
			break;
		case 2:
			runAdminMenu();
			break;
		case 3:
			exitMenu = false;
			break;
		default:
			cout << "������ ������ ���� ���!" << endl;
			break;
		}
		system("cls");
	}
}




