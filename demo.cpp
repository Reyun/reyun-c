#include <stdio.h>
#include <curl/curl.h>
 
int main(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    struct curl_slist *headers  = NULL;
 
    headers  = curl_slist_append(headers , "Content-Type: application/json");

    /* request with the built-in Accept: */ 
    curl_easy_setopt(curl, CURLOPT_URL, "http://log.reyun.com/receive/rest/loggedin");
    /* redo request with our own custom Accept: */ 

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers );
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"appid\":\"appid\",\"who\":\"sylar\",\"context\":{\"deviceid\":\"xxx\"}}");

    res = curl_easy_perform(curl);

    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
 
    /* free the custom headers */ 
    curl_slist_free_all(headers);
  }
  return 0;
}
