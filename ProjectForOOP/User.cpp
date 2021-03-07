#include "User.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

User::User()
{
}

User::User(string Login, string Password)
{
	this->login = Login;
	this->password = Password;
}

string User::getLogin() const
{
	return this->login;
}

string User::getPassword() const
{
	return this->password;
}

void User::input()
{
	cout << "Введите Логин" << endl;
	getline(cin, login);
	cout << "Введите Пароль" << endl;
	getline(cin, password);
}

void User::append(vector<User>& users, User user)
{
	users.push_back(user);
}

void User::remove(vector<User>& users, int index)
{
	if (index < 0 || index >= users.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		users.erase(users.begin() + index);
		cout << "Запись удалена" << endl;
	}
}

void User::edit(vector<User>& users, int index)
{
	if (index < 0 || index >= users.size())
	{
		cout << "Такого порядкого номера нет" << endl;
	}
	else {
		users[index].input();
	}
}

void User::printAsTable(vector<User>& users)
{
	printAsTable(users, " | ", '*');
}

void User::printAsTable(vector<User>& users, string verticalDelemitr, char gorizontalDelemitr)
{
	setlocale(0, "");
	int maxLenghtLogin = 5, maxLenghtPassword = 6, maxLenghtIndex = __max(to_string(users.size()).length(), 5);
	for (auto user : users) {
		maxLenghtLogin = __max(user.login.length(), maxLenghtLogin);
		maxLenghtPassword = __max(user.password.length(), maxLenghtPassword);
	}
	int totalLenght = maxLenghtLogin + maxLenghtPassword + maxLenghtIndex;
	string line(totalLenght + 7, gorizontalDelemitr);
	cout << line << endl;
	cout << '|' << setw(maxLenghtIndex) << "Номер" << verticalDelemitr
		<< setw(maxLenghtLogin) << "Логин" << verticalDelemitr
		<< setw(maxLenghtPassword) << "Пароль" << '|' << endl;
	cout << line << endl;
	int index = 1;
	for (auto user : users) {
		cout << '|' << setw(maxLenghtIndex) << index << verticalDelemitr
			<< setw(maxLenghtLogin) << user.login << verticalDelemitr
			<< setw(maxLenghtPassword) << user.password << '|' <<  endl;
		cout << line << endl ;
		index++;
	}
}


ostream& operator<<(ostream& out, const User& user)
{
	out << user.getLogin() << endl;
	out << user.getPassword();
	return out;
}

istream& operator>>(istream& in, User& user)
{
	string placeByResultStr;
	getline(in, user.login);
	getline(in, user.password);
	return in;
}
