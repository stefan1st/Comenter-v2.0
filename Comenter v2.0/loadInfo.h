#pragma once
#include <string>
#include <fstream>
using namespace std;
class loadInfo
{
private:
	string nume_fisier;
	string dataArray[8];
public:
	loadInfo(string);
	string getData(int);
	~loadInfo(void);
};