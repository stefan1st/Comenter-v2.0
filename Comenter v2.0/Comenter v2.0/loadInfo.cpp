#include "stdafx.h"
#include "loadInfo.h"


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
		}		
	}
}

string loadInfo::getData(int a)
{
	int numar_id = a;
	return (dataArray[numar_id]);
}


loadInfo::~loadInfo(void)
{
}