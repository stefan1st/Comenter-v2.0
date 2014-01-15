#pragma once
#include <string>
#include <fstream>
using namespace std;
class loadInfo
{
private:
	string nume_fisier;
	string *dataArray;
public:
	loadInfo(string);
	string getData(int);
	void setDataSize(int);
	int getDataSize();
	~loadInfo(void);
};