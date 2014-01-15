#include "stdafx.h"
#include "loadInfo.h"

void loadInfo::setDataSize(int n)
{
	int numData = n;
	string *dataArray = new string[numData];
}

loadInfo::loadInfo(string a)
{
	nume_fisier = a;

	string linie;

	ifstream fisier(nume_fisier);
	if (fisier.is_open())	
	{
		int i = 0;
		while (getline(fisier,linie))
		{
			dataArray[i] = linie;
			i++;
			loadInfo::setDataSize(i+1);
		}		
	}
}

string loadInfo::getData(int a)
{
	int numar_id = a;
	return (dataArray[numar_id]);
}

int loadInfo::getDataSize()
{
	return (sizeof(*dataArray)/sizeof(dataArray[0]));
}


loadInfo::~loadInfo(void)
{
}