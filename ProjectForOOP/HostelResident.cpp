#include "HostelResident.h"

HostelResident::HostelResident()
{
}
HostelResident::~HostelResident()
{

}
HostelResident::HostelResident(string fullName, int settlementYear, int room, string feedback, int entertainmentYear, string evictionReason, string residenceMark)
{
	this->fullName = fullName;
	this->settlementYear = settlementYear;
	this->room = room;
	this->feedback = feedback;
	this->entertainmentYear = entertainmentYear;
	this->evictionReason = evictionReason;
	this->residenceMark = residenceMark;
}

string HostelResident::getFullName()
{
	return fullName;
}

int HostelResident::getSettlementYear()
{
	return settlementYear;
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
	return entertainmentYear;
}

string HostelResident::getEvictionReason()
{
	return evictionReason;
}

string HostelResident::getResidenceMark()
{
	return residenceMark;
}

bool HostelResident::isCheckIn()
{
	return entertainmentYear != 0;
}

void HostelResident::Input()
{
	cout << "������� ���" << endl;
	getline(cin, fullName);
	cout << "������� ��� ���������" << endl;
	settlementYear = HelpFunctions::HelpFunctions::getNumber();
	cout << "������� ����� �������" << endl;
	room = HelpFunctions::HelpFunctions::getNumber();
	cout << "������� �����" << endl;
	getline(cin, feedback);
	cout << "������� ��� ���������" << endl;
	entertainmentYear = HelpFunctions::HelpFunctions::getNumber();
	if (isCheckIn())
	{
		evictionReason = "";
		cout << "������� ������� � ����������" << endl;
		getline(cin, residenceMark);
	}
	else {
		residenceMark = "";
		cout << "������� ������� ���������" << endl;
		getline(cin, evictionReason);

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
		maxLenghtFullName = max(HelpFunctions::lenghtOf(hostelResident.fullName), maxLenghtFullName);
		maxLenghtSettlementYear = max(HelpFunctions::lenghtOf(hostelResident.settlementYear), maxLenghtSettlementYear);
		maxLenghtRoom = max(HelpFunctions::lenghtOf(hostelResident.room), maxLenghtRoom);
		maxLenghtFeedback = max(HelpFunctions::lenghtOf(hostelResident.feedback), maxLenghtFeedback);
		maxLenghtEntertainmentYear = max(HelpFunctions::lenghtOf(hostelResident.entertainmentYear), maxLenghtEntertainmentYear);
		maxLenghtEvictionReason = max(HelpFunctions::lenghtOf(hostelResident.evictionReason), maxLenghtEvictionReason)
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
			<< setw(maxLenghtFullName) << hostelResident.fullName << verticalDelemitr
			<< setw(maxLenghtSettlementYear) << hostelResident.settlementYear << verticalDelemitr
			<< setw(maxLenghtRoom) << hostelResident.room << verticalDelemitr
			<< setw(maxLenghtFeedback) << hostelResident.feedback << verticalDelemitr
			<< setw(maxLenghtEntertainmentYear) << hostelResident.entertainmentYear << verticalDelemitr
			<< setw(maxLenghtEvictionReason) << hostelResident.evictionReason << verticalDelemitr
			<< setw(maxLenghtResidenceMark) << hostelResident.residenceMark << '|' << endl;
		cout << line << endl;
		index++;
	}
}

void HostelResident::SortByFunc(vector<HostelResident>& hostelResidents, bool (*comp)(HostelResident, HostelResident))
{
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetMusicalInstrument().GetName() < hostelResidentsecond.GetMusicalInstrument().GetName(); } //���������� ��� ���������� �� ������������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetFullName() < hostelResidentsecond.GetFullName(); } //���������� ��� ���������� �� ��������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.entertainmentYear() < hostelResidentsecond.entertainmentYear(); } //���������� �� ���� ���������
	//[](hostelResident hostelResidentFirst, hostelResident hostelResidentsecond) {return hostelResidentFirst.GetPlaceByResults() < hostelResidentsecond.GetPlaceByResults(); } //���������� ��� ���������� �� ������
	sort(hostelResidents.begin(), hostelResidents.end(), comp);
}

void HostelResident::sortByFIOAfterYear(vector<HostelResident>& hostelResidents, int year)
{
	vector<HostelResident> residentsAfterYear;
	for (int i = 0; i < hostelResidents.size(); i++)
	{
		if (hostelResidents[i].settlementYear >= year)
			residentsAfterYear.push_back(hostelResidents[i]);
	}
	if (residentsAfterYear.size() == 0)
	{
		cout << "����� ������� ���" << endl;
	}
	else
	{
		SortByFunc(residentsAfterYear, [](HostelResident hostelResidentFirst, HostelResident hostelResidentsecond) {return hostelResidentFirst.getFullName() < hostelResidentsecond.getFullName(); });
		printAsTable(residentsAfterYear);
	}
}

void HostelResident::whoLiveNow(vector<HostelResident>& hostelResidents)
{
	vector<HostelResident> peopleWhoLiveNow;
	for (int i = 0; i < hostelResidents.size(); i++)
	{
		if (hostelResidents[i].isCheckIn() == true)
			peopleWhoLiveNow.push_back(hostelResidents[i]);
	}
	if (peopleWhoLiveNow.size() == 0)
	{
		cout << "����� ������� ���" << endl;
	}
	else
	{
		printAsTable(peopleWhoLiveNow);
	}
}



void HostelResident::findByFIO(vector<HostelResident>& hostelResidents, string NameToFind)
{
	vector<HostelResident> FoundByNamehostelResidents;
	for (auto hostelResident : hostelResidents)
	{
		if (findSubstring(hostelResident.fullName, NameToFind))
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

bool HostelResident::findSubstring(string mainString, string subString)
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
	out << hostelResident.fullName << endl;
	out << hostelResident.settlementYear << endl;
	out << hostelResident.room << endl;
	out << hostelResident.feedback << endl;
	out << hostelResident.entertainmentYear << endl;
	out << hostelResident.evictionReason << endl;
	out << hostelResident.residenceMark;
	return out;
}

istream& operator>>(istream& in, HostelResident& hostelResident)
{
	string placeByResultStr;
	getline(in, hostelResident.fullName);
	in >> hostelResident.settlementYear;
	in >> hostelResident.room;
	getline(in, hostelResident.feedback);
	in >> hostelResident.entertainmentYear;
	getline(in, hostelResident.evictionReason);
	getline(in, hostelResident.residenceMark);
	return in;
}

