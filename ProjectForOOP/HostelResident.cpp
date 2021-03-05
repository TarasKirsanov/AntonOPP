#include "HostelResident.h"

HostelResident::HostelResident()
{
}
HostelResident::~HostelResident()
{

}
HostelResident::HostelResident(string full_name, int settlement_year, int room, string feedback, int entertainment_year, string eviction_reason, string residence_mark)
{
	this->full_name = full_name;
	this->settlement_year = settlement_year;
	this->room = room;
	this->feedback = feedback;
	this->entertainment_year = entertainment_year;
	this->eviction_reason = eviction_reason;
	this->residence_mark = residence_mark;
}

string HostelResident::getFullName()
{
	return full_name;
}

int HostelResident::getSettlementYear()
{
	return settlement_year;
}

int HostelResident::getRoom()
{
	return room;
}

string HostelResident::getFeedback()
{
	return feedback;
}

int HostelResident::getEntertainmentYear()
{
	return entertainment_year;
}

string HostelResident::getEvictionReason()
{
	return eviction_reason;
}

string HostelResident::getResidenceMark()
{
	return residence_mark;
}

bool HostelResident::isCheckIn()
{
	return entertainment_year != 0;
}

void HostelResident::Input()
{
	cout << "������� ���" << endl;
	getline(cin, full_name);
	cout << "������� ��� ���������" << endl;
	settlement_year = HelpFunctions::HelpFunctions::GetNumber();
	cout << "������� ����� �������" << endl;
	room = HelpFunctions::HelpFunctions::GetNumber();
	cout << "������� �����" << endl;
	getline(cin, feedback);
	cout << "������� ��� ���������" << endl;
	entertainment_year = HelpFunctions::HelpFunctions::GetNumber();
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

void HostelResident::append(vector<HostelResident>& hostelResidents, HostelResident hostelResident)
{
	hostelResidents.push_back(hostelResident);
}

void HostelResident::remove(vector<HostelResident>& hostelResidents, int index)
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

void HostelResident::edit(vector<HostelResident>& hostelResidents, int index)
{
	if (index < 0 || index >= hostelResidents.size())
	{
		cout << "������ ��������� ������ ���" << endl;
	}
	else {
		hostelResidents[index].Input();
	}

}

void HostelResident::printAsTable(vector<HostelResident>& hostelResidents)
{
	printAsTable(hostelResidents, " | ", '*');
}

void HostelResident::printAsTable(vector<HostelResident>& hostelResidents, string verticalDelemitr, char gorizontalDelemitr)
{
	setlocale(0, "");
	int maxLenghtFullName = 6, maxLenghtSettlementYear = 13, maxLenghtRoom = 7,
		maxLenghtFeedback = 5, maxLenghtEntertainmentYear = 13, maxLenghtEvictionReason = 7, maxLenghtResidenceMark = 20, maxLenghtIndex = max(HelpFunctions::lenghtOf(hostelResidents.size()), 6);
	for (auto hostelResident : hostelResidents) {
		maxLenghtFullName = max(HelpFunctions::lenghtOf(hostelResident.full_name), maxLenghtFullName);
		maxLenghtSettlementYear = max(HelpFunctions::lenghtOf(hostelResident.settlement_year), maxLenghtSettlementYear);
		maxLenghtRoom = max(HelpFunctions::lenghtOf(hostelResident.room), maxLenghtRoom);
		maxLenghtFeedback = max(HelpFunctions::lenghtOf(hostelResident.feedback), maxLenghtFeedback);
		maxLenghtEntertainmentYear = max(HelpFunctions::lenghtOf(hostelResident.entertainment_year), maxLenghtEntertainmentYear);
		maxLenghtEvictionReason = max(HelpFunctions::lenghtOf(hostelResident.eviction_reason), maxLenghtEvictionReason)
	}

	int totalLenght = maxLenghtFullName + maxLenghtSettlementYear + maxLenghtRoom + maxLenghtFeedback +
		maxLenghtEntertainmentYear + maxLenghtEvictionReason;
	string line(totalLenght + 23, gorizontalDelemitr);
	cout << line << endl;
	cout << '|' << setw(maxLenghtIndex) << "������" << verticalDelemitr
		<< setw(maxLenghtFullName) << "�.�.�." << verticalDelemitr
		<< setw(maxLenghtSettlementYear) << "��� ���������" << verticalDelemitr
		<< setw(maxLenghtRoom) << "�������" << verticalDelemitr
		<< setw(maxLenghtFeedback) << "�����" << verticalDelemitr
		<< setw(maxLenghtEntertainmentYear) << "��� ���������" << verticalDelemitr
		<< setw(maxLenghtEvictionReason) << "�������" << verticalDelemitr
		<< setw(maxLenghtResidenceMark) << "������� � ����������" << '|' << endl;
	cout << line << endl << endl;
	int index = 1;
	for (auto hostelResident : hostelResidents) {
		cout << '|' << setw(maxLenghtIndex) << index << verticalDelemitr
			<< setw(maxLenghtFullName) << hostelResident.full_name << verticalDelemitr
			<< setw(maxLenghtSettlementYear) << hostelResident.settlement_year << verticalDelemitr
			<< setw(maxLenghtRoom) << hostelResident.room << verticalDelemitr
			<< setw(maxLenghtFeedback) << hostelResident.feedback << verticalDelemitr
			<< setw(maxLenghtEntertainmentYear) << hostelResident.entertainment_year << verticalDelemitr
			<< setw(maxLenghtEvictionReason) << hostelResident.eviction_reason << verticalDelemitr
			<< setw(maxLenghtResidenceMark) << hostelResident.residence_mark << '|' << endl;
		cout << line << endl;
		index++;
	}
}

void HostelResident::SortByFunc(vector<HostelResident>& hostelResidents, bool (*comp)(HostelResident, HostelResident))
{
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetMusicalInstrument().GetName() < hostelResidentsecond.GetMusicalInstrument().GetName(); } //���������� ��� ���������� �� ������������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetFullName() < hostelResidentsecond.GetFullName(); } //���������� ��� ���������� �� ��������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetDate() < hostelResidentsecond.GetDate(); } //���������� ��� ���������� �� ���� ��������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetPlaceByResults() < hostelResidentsecond.GetPlaceByResults(); } //���������� ��� ���������� �� ������
	sort(hostelResidents.begin(), hostelResidents.end(), comp);
}

void HostelResident::sortByYearAfterYear(vector<HostelResident>& hostelResidents, int year)
{
	vector<HostelResident> residentsAfterYear;
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
		SortByFunc(residentsAfterYear, [](HostelResident hostelResidentFirst, HostelResident hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
	
	}
}



void HostelResident::FindByFIO(vector<HostelResident>& hostelResidents, string NameToFind)
{
	vector<HostelResident> FoundByNamehostelResidents;
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
		HostelResident::SortByFunc(FoundByNamehostelResidents, [](HostelResident hostelResidentFirst, HostelResident hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
		HostelResident::printAsTable(FoundByNamehostelResidents);
	}

}

bool HostelResident::FindSubstring(string mainString, string subString)
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





ostream& operator<<(ostream& out, const HostelResident& hostelResident)
{
	out << hostelResident.full_name << endl;
	out << hostelResident.settlement_year << endl;
	out << hostelResident.room << endl;
	out << hostelResident.feedback << endl;
	out << hostelResident.entertainment_year << endl;
	out << hostelResident.eviction_reason << endl;
	out << hostelResident.residence_mark;
	return out;
}

istream& operator>>(istream& in, HostelResident& hostelResident)
{
	string placeByResultStr;
	getline(in, hostelResident.full_name);
	in >> hostelResident.settlement_year;
	in >> hostelResident.room;
	getline(in, hostelResident.feedback);
	in >> hostelResident.entertainment_year;
	getline(in, hostelResident.eviction_reason);
	getline(in, hostelResident.residence_mark);
	return in;
}

