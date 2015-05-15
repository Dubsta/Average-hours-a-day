// toggleData() uses curl to make an HTTP call to toggl API, then stores the json
// response in a file called yearsum.c

#include <curl/curl.h>
#include <stdio.h>
#include "private.c" // Your password, apikey, and url for calling toggl summary
int togglData()
{
  FILE* yearsum;
  if ((yearsum = fopen("yearsum.c", "w+")) == NULL)
  {
    printf("There was a problem with the yearsum file");
    return -1;
  }

  CURLcode firstCall;
  CURL *curlHandle;

  curlHandle = curl_easy_init();
  // URL from private.c
  curl_easy_setopt(curlHandle, CURLOPT_URL, FROMPRIVATEFILE);
  // PASSWORD from private.c
  curl_easy_setopt(curlHandle, CURLOPT_USERPWD, PASSWORD);
  curl_easy_setopt(curlHandle, CURLOPT_USERAGENT, "curl/7.37.1");
  curl_easy_setopt(curlHandle, CURLOPT_MAXREDIRS, 50L);
  curl_easy_setopt(curlHandle, CURLOPT_CUSTOMREQUEST, "GET");
  curl_easy_setopt(curlHandle, CURLOPT_TCP_KEEPALIVE, 1L);
  curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, yearsum);

  firstCall = curl_easy_perform(curlHandle);
  curl_easy_cleanup(curlHandle);
  curlHandle = NULL;

  fclose(yearsum);

  return (int)firstCall;
}


// just for now.
int main(void)
{
  return togglData();
}
