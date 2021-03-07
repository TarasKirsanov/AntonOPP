#pragma once
#include <string>
#include <iostream>
#define max(a,b) a > b ? a : b;
using namespace std;
class HelpFunctions
{
public:

	static int getNumber();
	static bool isNumber(string s);
	static int lenghtOf(int n);
	static int lenghtOf(string s);
};

