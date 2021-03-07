#pragma once
#include "HostelResident.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "FileWorker.h"
#include <fstream>
using namespace std;

class Administrator
{
public:
	Administrator();
	Administrator(string userFileName, string residentsFileName);
	void createFile(string fileName);
	void openFile(string fileName);
	void removeFile(string fileName);
	void viewResidents();
	void appendResidents(HostelResident member);
	void deleteResidents(int index);
	void editResidents(int index);
	void appendUser(User user);
	void deleteUser(int index);
	void editUser(int index);
	void viewUsers();
private:
	
	vector<HostelResident> residents;
	vector<User> users;
	string residentsFileName;
	string userFileName;
};

