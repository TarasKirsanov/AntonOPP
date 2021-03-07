#include "FileWorker.h"

vector<HostelResident> FileWorker::getResidentsFromFile(string fileName)
{
	vector<HostelResident> members;
	ifstream file_in(fileName);

	if (not isExists(fileName) )
	{
		cout << "Такого файла не существует";
		return members;
	}
	if (file_in.peek() == EOF)
	{
		return members;
	}


	HostelResident member;
	while (file_in >> member && file_in.peek() != EOF)
	{
		members.push_back(member);
	}
	return members;
}

vector<User> FileWorker::getUsersFromFile(string fileName)
{
	vector<User> users;
	ifstream file_in(fileName);
	if (not isExists(fileName))
	{
		cout << "Такого файла не существует";
		return users;
	}
	if (file_in.peek() == EOF)
	{
		return users;
	}
	int usersCount;
	string usersCountStr;
	User user;

	while (file_in >> user && file_in.peek() != EOF)
	{
		users.push_back(user);
	}
	return users;
}


void FileWorker::writeResidentsToFile(string fileName, vector<HostelResident> members)
{
	ofstream file_out(fileName); 
	if (not isExists(fileName))
	{
		cout << "Такого файла не существует";
	}
	else
	{

		for (int i = 0; i + 1 < members.size(); i++)
		{
			file_out << members[i] << endl;
		}
		if (members.size() != 0)
		{
			file_out << members[members.size() - 1];
		}

	}
	file_out.close();

}

void FileWorker::writeUsersToFile(string fileName, vector<User> users)
{
	ofstream file_out(fileName);

	if (not isExists(fileName))
	{
		cout << "Такого файла не существует";
	}
	else
	{
		for (int i = 0; i + 1 < users.size(); i++)
		{
			file_out << users[i] << endl;
		}
		if (users.size() > 0)
		{
			file_out << users[users.size() - 1];
		}
	}
	file_out.close();
}

bool FileWorker::isExists(string fileName)
{
	ifstream fin(fileName);
	bool isExists = fin.is_open();
	fin.close();
	return isExists;
}



