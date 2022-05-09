#include<ios>
#include<iostream>
#include<curl/curl.h>

#include<string>
#include<cstring>

using namespace std ;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void test_url(const char *url)
{

CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }
  
}
static size_t WriteCallback2(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc ,  const char *argv[])
{


if(argc>1){

  char data[1024];
  const char *data1 = argv[1];
  int data2 =  atoi(argv[2]);
  sprintf(data,"http://localhost:8022/Profile.php?username=%s&id=%d",data1,data2);
  test_url(data);

}

else test_url("http://localhost:8022/Profile.php?username=ayoubsmayen&id=12");


    return  1  ;

}