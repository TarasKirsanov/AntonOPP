
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	User(string Login, string Password);

	string getLogin() const;
	string getPassword() const;
	void input();
	static void append(vector<User>& users, User user);
	static void remove(vector<User>& users, int index);
	static void edit(vector<User>& users, int index);
	static void printAsTable(vector<User>& users);
	static void printAsTable(vector<User>& users, string verticalDelemitr, char gorizontalDelemitr);

	friend ostream& operator<<(ostream& out, const User& user);
	friend istream& operator>>(istream& in, User& user);


private:
	string login;
	string password;
};

