#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include "HelpFunctions.h"
using namespace std;

class HostelResidents
{
public:
	HostelResidents();
	~HostelResidents();
	HostelResidents(string full_name, int settlement_year, int room, string feedback,int entertainment_year, string eviction_reason, string residence_mark);
	string getFullName();
	int getSettlementYear();
	int getRoom();
	string getFeedback();
	int getEntertainmentYear();
	string getEvictionReason();
	string getResidenceMark();
	bool isCheckIn();
	void Input();
	static void append(vector<HostelResidents>& hostelResidents, HostelResidents hostelResident);
	static void remove(vector<HostelResidents>& hostelResidents, int index);
	static void Edit(vector<HostelResidents>& hostelResidents, int index);
	static void printAsTable(vector<HostelResidents>& hostelResidents);
	static void printAsTable(vector<HostelResidents>& hostelResidents, string verticalDelemitr, char gorizontalDelemitr);
	static void SortByFunc(vector<HostelResidents>& hostelResidents, bool (*comp)(HostelResidents,HostelResidents));
	static void sortByYearAfterYear(vector<HostelResidents>& hostelResidents, int year);
	static void FindByFIO(vector<HostelResidents>& hostelResidents , string NameToFind);
	static bool FindSubstring(string mainString, string subString);
	
	friend ostream& operator<<(ostream& out, const HostelResidents& member);
	friend istream& operator>>(istream& in, HostelResidents& member);
private:
	string full_name;
	int settlement_year;
	int room;
	string feedback;
	int entertainment_year;
	string eviction_reason;
	string residence_mark;
};

