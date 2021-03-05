#include "HelpFunctions.h"
int HelpFunctions::GetNumber()
{
	string num;
	int k;
	while (true)
	{
		getline(cin, num);
		try
		{
			k = stoi(num);
			break;
		}
		catch (const std::exception&)
		{
			cout << "¬ведите целое число" << endl;
		}

	}
	return k;
}

bool HelpFunctions::isNumber(string s)
{
	for (int a = 0; a < s.length(); a++) {
		if (s[a] != 45) {
			if ((s[a] < 48) || (s[a] > 57))  return false;
		}
	}
	return true;
}

int HelpFunctions::lenghtOf(int n)
{
	return lenghtOf(to_string(n));
}

int HelpFunctions::lenghtOf(string s)
{
	return s.length();
}
