#include <stdio.h>
#include <curl/curl.h>

int
main(void)
{
	CURL		*curl;
	FILE		*fp;
	CURLcode	res;
	char *url = "http://stackoverflow.com";
	char ofile[FILENAME_MAX] = "page.html";
	curl = curl_easy_init();
	if (curl) {
		fp = fopen(ofile, "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		fclose(fp);
	}

	return 0;
}
