#pragma once

#include <string>
using namespace std;

class pCurl
{
private:
	string email;
	string contentPost;
	string url;
public:
	void setUrl(string);			//Setam url de postare al wp-ului
	string getUrl();				//Returneaza url-ul de wp pe care l-am setat pentru postare
	pCurl(int,int,int);
	~pCurl(void);
};