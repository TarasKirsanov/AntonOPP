#include "hostelResident.h"
#include "FileWorker.h"
#include "Menu.h"
HostelResidents::HostelResidents()
{
}
HostelResidents::~HostelResidents()
{

}
HostelResidents::HostelResidents(string full_name, int settlement_year, int room, string feedback, int entertainment_year, string eviction_reason, string residence_mark)
{
	this->full_name = full_name;
	this->settlement_year = settlement_year;
	this->room = room;
	this->feedback = feedback;
	this->entertainment_year = entertainment_year;
	this->eviction_reason = eviction_reason;
	this->residence_mark = residence_mark;
}

string HostelResidents::getFullName()
{
	return full_name;
}

int HostelResidents::getSettlementYear()
{
	return settlement_year;
}

int HostelResidents::getRoom()
{
	return room;
}

string HostelResidents::getFeedback()
{
	return feedback;
}

int HostelResidents::getEntertainmentYear()
{
	return entertainment_year;
}

string HostelResidents::getEvictionReason()
{
	return eviction_reason;
}

string HostelResidents::getResidenceMark()
{
	return residence_mark;
}

bool HostelResidents::isCheckIn()
{
	return entertainment_year != 0;
}

void HostelResidents::Input()
{
	cout << "������� ���" << endl;
	getline(cin, full_name);
	cout << "������� ��� ���������" << endl;
	settlement_year = Menu::GetNumber();
	cout << "������� ����� �������" << endl;
	room = Menu::GetNumber();
	cout << "������� �����" << endl;
	getline(cin, feedback);
	cout << "������� ��� ���������" << endl;
	entertainment_year = Menu::GetNumber();
	if (isCheckIn())
	{
		eviction_reason = "";
		cout << "������� ������� � ����������" << endl;
		getline(cin, residence_mark);
	}
	else {
		residence_mark = "";
		cout << "������� ������� ���������" << endl;
		getline(cin, eviction_reason);

	}
}

void HostelResidents::append(vector<HostelResidents>& hostelResidents, HostelResidents hostelResident)
{
	hostelResidents.push_back(hostelResident);
}

void HostelResidents::remove(vector<HostelResidents>& hostelResidents, int index)
{
	if (index < 0 || index >= hostelResidents.size())
	{
		cout << "������ ��������� ������ ���" << endl;
	}
	else {
		hostelResidents.erase(hostelResidents.begin() + index);
		cout << "������ �������" << endl;
	}
}

void HostelResidents::Edit(vector<HostelResidents>& hostelResidents, int index)
{
	if (index < 0 || index >= hostelResidents.size())
	{
		cout << "������ ��������� ������ ���" << endl;
	}
	else {
		hostelResidents[index].Input();
	}

}

void HostelResidents::printAsTable(vector<HostelResidents>& hostelResidents)
{
	printAsTable(hostelResidents, " | ", '*');
}

void HostelResidents::printAsTable(vector<HostelResidents>& hostelResidents, string verticalDelemitr, char gorizontalDelemitr)
{
	setlocale(0, "");
	int maxLenghtFullName = 6, maxLenghtSettlementYear = 13, maxLenghtRoom = 7,
		maxLenghtFeedback = 5, maxLenghtEntertainmentYear = 13, maxLenghtEvictionYear = 7, maxLenghtResidenceMark = 20;
	for (auto hostelResident : hostelResidents) {
		maxLenghtFullName = max(HelpFunctions::lenghtOf(hostelResident.full_name), maxLenghtFullName);
		maxLenghtSettlementYear = max(HelpFunctions::lenghtOf(hostelResident.settlement_year), maxLenghtSettlementYear);
		maxLenghtRoom = max(HelpFunctions::lenghtOf(hostelResident.room), maxLenghtRoom);
		maxLenghtFeedback = max(HelpFunctions::lenghtOf(hostelResident.feedback), maxLenghtFeedback);
		maxLenghtEntertainmentYear = max(HelpFunctions::lenghtOf(hostelResident.entertainment_year), maxLenghtEntertainmentYear);
		maxLenghtEvictionYear = max(HelpFunctions::lenghtOf(hostelResident.eviction_reason), )
	}

	int totalLenght = maxLenghtFullName + maxLenghtCity + maxLenghtSex + maxLenghtDate +
		maxLenghtInstrumentName + maxLenghtPhoneNumber + maxLenghtPlace + maxLenghtIndex;
	string line(totalLenght + 23, gorizontalDelemitr);
	cout << line << endl;
	cout << '|' << setw(maxLenghtIndex) << "�����" << verticalDelemitr
		<< setw(maxLenghtFullName) << "�.�.�." << verticalDelemitr
		<< setw(maxLenghtSex) << "���" << verticalDelemitr
		<< setw(maxLenghtDate) << "����" << verticalDelemitr
		<< setw(maxLenghtCity) << "�����" << verticalDelemitr
		<< setw(maxLenghtInstrumentName) << "��� �����������" << verticalDelemitr
		<< setw(maxLenghtPhoneNumber) << "����� ��������" << verticalDelemitr
		<< setw(maxLenghtPlace) << "�����" << '|' << endl;
	cout << line << endl << endl;
	int index = 1;
	for (auto hostelResident : hostelResidents) {
		cout << '|' << setw(maxLenghtIndex) << index << verticalDelemitr << setw(maxLenghtFullName) << hostelResident.full_name << verticalDelemitr
			<< setw(maxLenghtSex) << hostelResident.sex << verticalDelemitr
			<< setw(maxLenghtDate) << hostelResident.date << verticalDelemitr
			<< setw(maxLenghtCity) << hostelResident.city << verticalDelemitr
			<< setw(maxLenghtInstrumentName) << hostelResident.musicalInstrument.GetName() << verticalDelemitr
			<< setw(maxLenghtPhoneNumber) << hostelResident.phoneNumber << verticalDelemitr
			<< setw(maxLenghtPlace) << hostelResident.placeByResult << '|' << endl;
		cout << line << endl;
		index++;
	}
}

void HostelResidents::SortByFunc(vector<HostelResidents>& hostelResidents, bool (*comp)(HostelResidents, HostelResidents))
{
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetMusicalInstrument().GetName() < hostelResidentsecond.GetMusicalInstrument().GetName(); } //���������� ��� ���������� �� ������������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetFullName() < hostelResidentsecond.GetFullName(); } //���������� ��� ���������� �� ��������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetDate() < hostelResidentsecond.GetDate(); } //���������� ��� ���������� �� ���� ��������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetPlaceByResults() < hostelResidentsecond.GetPlaceByResults(); } //���������� ��� ���������� �� ������
	sort(hostelResidents.begin(), hostelResidents.end(), comp);
}

void HostelResidents::sortByYearAfterYear(vector<HostelResidents>& hostelResidents, int year)
{
	vector<HostelResidents> residentsAfterYear;
	for (int i = 0; i < hostelResidents.size(); i++)
	{
		if (hostelResidents[i].settlement_year >= year)
			residentsAfterYear.push_back(hostelResidents[i]);
	}
	if (residentsAfterYear.size() == 0)
	{
		cout << "����� ������� ���" << endl;
	}
	else
	{
		SortByFunc(residentsAfterYear, [](HostelResidents hostelResidentFirst, HostelResidents hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
		printAsTable();
	}
}



void HostelResidents::FindByFIO(vector<HostelResidents>& hostelResidents, string NameToFind)
{
	vector<HostelResidents> FoundByNamehostelResidents;
	for (auto hostelResident : hostelResidents)
	{
		if (FindSubstring(hostelResident.full_name, NameToFind))
			FoundByNamehostelResidents.push_back(hostelResident);
	}
	if (FoundByNamehostelResidents.size() == 0)
	{
		cout << "���������� � ������ ������� �� �������!" << endl;
	}
	else
	{
		HostelResidents::SortByFunc(FoundByNamehostelResidents, [](HostelResidents hostelResidentFirst, HostelResidents hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
		HostelResidents::printAsTable(FoundByNamehostelResidents);
	}

}

bool HostelResidents::FindSubstring(string mainString, string subString)
{
	int size;
	if (mainString.size() > subString.size())
		size = subString.size();
	else
		size = mainString.size();
	for (int i = 0; i <= size - 1; i++)
	{
		if (mainString[i] != subString[i])
			return false;
	}
	return true;
}





ostream& operator<<(ostream& out, const HostelResidents& hostelResident)
{
	out << hostelResident.full_name << endl;
	out << hostelResident.sex << endl;
	out << hostelResident.date << endl;
	out << hostelResident.city << endl;
	out << hostelResident.phoneNumber << endl;
	out << hostelResident.musicalInstrument << endl;
	out << hostelResident.placeByResult;
	return out;
}

istream& operator>>(istream& in, HostelResidents& hostelResident)
{
	string placeByResultStr;
	getline(in, hostelResident.full_name);
	getline(in, hostelResident.sex);
	in >> hostelResident.date;
	getline(in, hostelResident.city);
	getline(in, hostelResident.phoneNumber);
	in >> hostelResident.musicalInstrument;
	getline(in, placeByResultStr);

	hostelResident.placeByResult = stoi(placeByResultStr);
	return in;
}

