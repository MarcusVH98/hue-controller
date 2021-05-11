#include<stdio.h>
#include<curl/curl.h>

#include<json-c/json.h>

int main()
{
    CURL *curl;
    CURLcode res;

    // URL with username and bulb id
    char adr[] = "http://192.168.0.144/api/hpWNy9jfbACROBTB8diURwZQabXua0KrGcFV3pRe/lights/1/state";
    
    char adrGet[] = "http://192.168.0.144/api/hpWNy9jfbACROBTB8diURwZQabXua0KrGcFV3pRe/lights";

    curl = curl_easy_init();
    if (curl)
    {
	struct curl_slist *header = NULL;

	// Setting header info
	//header = curl_slist_append(header, "Content-Type: application/json");

	// Applying header
	//curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
	// Which url to use for the upcoming request
	curl_easy_setopt(curl, CURLOPT_URL, adrGet);
	//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_struct);
	


	// GET / PUT etc options set
	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
	
	// Enable PUT
	//curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

	// perform the commands
	res = curl_easy_perform(curl);

	// Check for errors
	if (res != CURLE_OK)
	{
	    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	}

	// Send the data to replace
	//res = curl_easy_send(curl, )

	// Always cleanup
	//curl_slist_free_all(header);
	curl_easy_cleanup(curl);
    }

    return 0;
}
