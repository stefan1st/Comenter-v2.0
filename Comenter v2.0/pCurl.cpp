#include "stdafx.h"
#include "pCurl.h"

using namespace std;


void pCurl::setUrl(string u)
{
	url = u;
}

string pCurl::getUrl()
{
	return (url);
}

pCurl::pCurl(int a, int b, int c)
{
	int x=a,y=b,z=c;
	setUrl("http://www.artnudephotos.net/wp-comments-post.php");


	loadInfo nume("nume.txt");
	loadInfo comentariu("comentariu.txt");
	loadInfo url("url.txt");

	email = nume.getData(x) + "@yahoo.com";
	contentPost = "author=" +nume.getData(x)+ "&email=" +email+ "&url=&comment=" +comentariu.getData(y)+ "&submit=&comment_post_ID=" +url.getData(z)+ "&comment_post_ID=" +url.getData(z)+ "&comment_parent=0";
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, getUrl().c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, contentPost.c_str());
//		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1L);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10);
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, true);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, '30');
		curl_easy_setopt(curl, CURLOPT_FRESH_CONNECT, false);

		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}


pCurl::~pCurl(void)
{
}
