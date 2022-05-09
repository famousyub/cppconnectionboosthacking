#include <iostream>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode result;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if (curl) {

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com/");
    // If you want to set any more options, do it here, before making the request.

    // Perform the request which prints to stdout
    result = curl_easy_perform(curl);

    // Error check
    if (result != CURLE_OK) {
      std::cerr << "Error during curl request: " 
                << curl_easy_strerror(result) << std::endl;
    }

    curl_easy_cleanup(curl);
  } else {
    std::cerr << "Error initializing curl." << std::endl;
  }

  curl_global_cleanup();

  return 0;
}