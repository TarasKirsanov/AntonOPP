#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include "HelpFunctions.h"
#include "Menu.h"

using namespace std;

class HostelResident
{
public:
	HostelResident();
	~HostelResident();
	HostelResident(string full_name, int settlement_year, int room, string feedback,int entertainment_year, string eviction_reason, string residence_mark);
	string getFullName();
	int getSettlementYear();
	int getRoom();
	string getFeedback();
	int getEntertainmentYear();
	string getEvictionReason();
	string getResidenceMark();
	bool isCheckIn();
	void Input();
	static void append(vector<HostelResident>& hostelResidents, HostelResident hostelResident);
	static void remove(vector<HostelResident>& hostelResidents, int index);
	static void edit(vector<HostelResident>& hostelResidents, int index);
	static void printAsTable(vector<HostelResident>& hostelResidents);
	static void printAsTable(vector<HostelResident>& hostelResidents, string verticalDelemitr, char gorizontalDelemitr);
	static void sortByYearAfterYear(vector<HostelResident>& hostelResidents, int year);
	static void SortByFunc(vector<HostelResident>& hostelResidents, bool (*comp)(HostelResident,HostelResident));
	static void FindByFIO(vector<HostelResident>& hostelResidents , string NameToFind);
	static bool FindSubstring(string mainString, string subString);
	
	friend ostream& operator<<(ostream& out, const HostelResident& member);
	friend istream& operator>>(istream& in, HostelResident& member);
private:
	string full_name;
	int settlement_year;
	int room;
	string feedback;
	int entertainment_year;
	string eviction_reason;
	string residence_mark;
};

