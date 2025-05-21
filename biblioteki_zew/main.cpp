#include <iostream>
#include <string>
#include <curl/curl.h>
using namespace std;
 
class IMGW{
public:
    IMGW(){
        curl_=curl_easy_init();
    }

    ~IMGW(){
        if(curl_){
            curl_easy_cleanup(curl_);
        }
    }
    void WeatherData(const string& url){
        curl_easy_setopt(curl_, CURLOPT_URL, "https://danepubliczne.imgw.pl/api/data/synop/id/12360/format/csv");
        // curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, fwrite);

        // /* we pass our 'chunk' struct to the callback function */
        // curl_easy_setopt(curl_, CURLOPT_WRITEDATA, (void *)stdout);
        CURLcode res = curl_easy_perform(curl_);
        if(CURLE_OK == res) {
    }
    }
private:
    CURL * curl_;
};


int main(void)
{
    IMGW imgw;
    imgw.WeatherData("");
    return 0;
}