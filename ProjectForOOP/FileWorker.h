#pragma once
#include "HostelResident.h"
#include "User.h"
#include <vector>
#include <fstream>
class FileWorker
{
public:
	//static vector<Member> GetMembersFromFile(ifstream& file_in);
	static vector<HostelResident> getResidentsFromFile(string fileName);
	static vector<User> getUsersFromFile(string fileName);
	static void writeResidentsToFile(string fileName, vector<HostelResident> members);
	static void writeUsersToFile(string fileName, vector<User> users);
	static bool isExists(string fileName);
private:
	FileWorker() {}
	
};

