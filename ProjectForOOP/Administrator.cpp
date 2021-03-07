#include "Administrator.h"

Administrator::Administrator()
{

}
Administrator::Administrator(string userFileName, string residentsFileName)
{
	this->residentsFileName = residentsFileName;
	this->userFileName = userFileName;

	//file_in.open(userFileName);
	users = FileWorker::getUsersFromFile(userFileName);

	residents = FileWorker::getResidentsFromFile(residentsFileName);

}
void Administrator::createFile(string fileName)
{
	if (FileWorker::isExists(fileName))
	{
		cout << "���� ��� ����������" << endl;
	}
	else
	{
		ofstream fout(fileName);
		fout.close();
		cout << "���� ������" << endl;
	}
}
void Administrator::openFile(string fileName)
{
	residents = FileWorker::getResidentsFromFile(fileName);
	cout << "���� ������" << endl;
}
void Administrator::removeFile(string fileName)
{
	if (not FileWorker::isExists(fileName))
	{
		cout << "������ ����� ���" << endl;
	}
	else
	{
		if (remove(fileName.c_str()) == -1)
		{
			cout << "���� �� ���������� �������" << endl;
		}
		else
		{
			cout << "���� ������" << endl;
		}
	}
}

void Administrator::viewResidents()
{
	HostelResident::printAsTable(residents);
}

void Administrator::appendResidents(HostelResident resident)
{

	HostelResident::append(residents, resident);
	FileWorker::writeResidentsToFile(residentsFileName, residents);

}

void Administrator::deleteResidents(int index)
{

	HostelResident::remove(residents, index);
	FileWorker::writeResidentsToFile(residentsFileName, residents);


}

void Administrator::editResidents(int index)
{

	HostelResident::edit(residents, index);
	FileWorker::writeResidentsToFile(residentsFileName, residents);


}

void Administrator::appendUser(User user)
{

	User::append(users, user);
	FileWorker::writeUsersToFile(userFileName, users);
}

void Administrator::deleteUser(int index)
{

	User::remove(users, index);
	FileWorker::writeUsersToFile(userFileName, users);
}

void Administrator::editUser(int index)
{

	User::edit(users, index);
	FileWorker::writeUsersToFile(userFileName, users);
}

void Administrator::viewUsers()
{
	User::printAsTable(users);
}




