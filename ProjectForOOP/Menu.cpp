#include "Menu.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>
#include "HostelResident.h"
#include "FileWorker.h"
#include "Administrator.h"
using namespace std;

void Menu::RunMemberMenu()
{
	setlocale(0, "");

	string userFileName, memberFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� members.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	memberFileName = memberFileName.empty() ? "members.txt" : memberFileName;
	
	vector<HostelResident> members = FileWorker::get_members_from_file(memberFileName);
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
		int choose = HelpFunctions::GetNumber();
		system("cls");
		switch (choose)
		{
		case 1:
		{
			HostelResident::printAsTable(members);
		}
		break;
		case 2:
		{
			cout << "������� ��� ��� ������: " << endl;
			string name;
			getline(cin, name);
			HostelResident::FindByFIO(members, name);
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
				cout << "2. �� �����" << endl;
				cout << "3. �� ���� ��������" << endl;
				cout << "4. �����" << endl;
				int SubChoose = HelpFunctions::GetNumber();
				system("cls");
				/*switch (SubChoose)
				{
				case 1:
					cout << "�������������� �� �����;" << endl;
					HostelResident::SortByFunc(members, [](HostelResident memberFirst, HostelResident memberSecond) {return memberFirst.getFullName() < memberSecond.getFullName(); });
					HostelResident::printAsTable(members);
					break;
				case 2:
					cout << "�������������� �� �����;" << endl;
					HostelResident::SortByFunc(members, [](HostelResident memberFirst, HostelResident memberSecond) {return memberFirst.GetPlaceByResults() < memberSecond.GetPlaceByResults(); });
					HostelResident::printAsTable(members);
					break;
				case 3:
					cout << "�������������� �� ���� ��������;" << endl;
					HostelResident::SortByFunc(members, [](HostelResident memberFirst, HostelResident memberSecond) {return memberFirst.GetDate() < memberSecond.GetDate(); });
					HostelResident::printAsTable(members);
					break;
				case 4:
					exitSubMenu = false;
					break;
				default:
					cout << "������ ������ ���� - ���!" << endl;
					break;
				}*/
				system("pause");
			}
		}
		break;
		/*case 4:
		{
			cout << "������ �������������� �������:" << endl << endl;
			HostelResident::PrintFirstThreePlaceFrommAllInstrument(members);
		}
		break;
		case 5:
		{
			cout << "������ �������������� �������:" << endl << endl;
			HostelResident::PrintYougestWinner(members);
		}
		break;*/
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

void Menu::RunAdminMenu()
{
	setlocale(0, "");
	string userFileName, memberFileName;
	cout << "������� ��� �����, ��� �������������� ������������ (�� ��������� users.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, userFileName);
	userFileName = userFileName.empty() ? "users.txt" : userFileName;
	cout << "������� ��� �����, ��� �������������� ��������� (�� ��������� members.txt), ������� Enter ��� ������������� ����� �� ���������" << endl;
	getline(cin, memberFileName);
	memberFileName = memberFileName.empty() ? "members.txt" : memberFileName;

	Administrator admin(userFileName, memberFileName);
	bool exitMenu = true;
	while (exitMenu)
	{
		system("cls");
		cout << "1. ���������� �������� �������� ������������:" << endl;
		cout << "2. ������ � ������ ������:" << endl;
		cout << "3. ������ � �������:" << endl;
		cout << "4. �����" << endl;
		int choose = HelpFunctions::GetNumber();
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
				int SubChoose = HelpFunctions::GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.view_users();
				}
				break;
				case 2:
				{
					User user;
					user.Input();
					admin.AppendUser(user);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = HelpFunctions::GetNumber() - 1;
					admin.edit_user(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������������:" << endl;
					int number = HelpFunctions::GetNumber() - 1;
					admin.delete_user(number);
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
				int SubChoose = HelpFunctions::GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.create_file(fileName);
				}
				break;
				case 2:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.open_file(fileName);
				}
				break;
				case 3:
				{
					cout << "������� ��� �����:" << endl;
					string fileName;
					getline(cin, fileName);
					admin.remove_file(fileName);
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
				int SubChoose = HelpFunctions::GetNumber();
				system("cls");
				switch (SubChoose)
				{
				case 1:
				{
					admin.view_members();
				}
				break;
				case 2:
				{
					HostelResident member;
					member.Input();
					admin.append_member(member);
				}
				break;
				case 3:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = HelpFunctions::GetNumber() - 1;
					admin.delete_member(number);
				}
				break;
				case 4:
				{
					cout << "������� ���������� ����� ������:" << endl;
					int number = HelpFunctions::GetNumber() - 1;
					admin.edit_member(number);
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

void Menu::FirstMenu()
{
	setlocale(0, "");
	bool exitMenu = true;
	while (exitMenu)
	{
		cout << "�������� ����:" << endl;
		cout << "1. ������������" << endl;
		cout << "2. �������������" << endl;
		cout << "3. �����" << endl;
		int menuChoose = HelpFunctions::GetNumber();
		system("cls");
		switch (menuChoose)
		{
		case 1:
			RunMemberMenu();
			break;
		case 2:
			RunAdminMenu();
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




