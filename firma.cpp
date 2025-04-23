#include <iostream>
#include <cstdlib>
#include <string>
#include <format>
#include <chrono>
#include <cctype>
#include <tuple>
#include <algorithm>
using namespace std;


class Firma{
    public:
        std::string name;
        std::string nip;
        std::string date;
        std::string mail;
        Firma(const string &_name,const string &_nip,const string &_date,const string &_mail){
            if (_name.length() < 3 || _name.length()>100){
                throw length_error("Dlugosc nazwy firmy musi byc w przedziale [3;100]");
            }

            if(_nip.length()!=10){
                throw length_error("Numer NIP musi sie skladac z 10 znakow");
            }

            for(char i: _nip){
                if(!isdigit(i)){
                    throw invalid_argument("NIP Musi sie skladac z samych cyfr");
                }
            }

            int sum=0;
            int weights[] = {6,5,7,2,3,4,5,6,7}; 
            for(int i=0;i<9;i++){
                int number = _nip[i] - '0';
                int a = number * weights[i];
                sum=sum+a;
            }

            int controldigit=sum%11;
            int lastdigit=_nip[9]-'0';
            if(controldigit!=lastdigit){
                throw domain_error("Dziesiąta cyfra numeru NIP musi być zgodna z wyliczoną cyfrą kontrolną");
            }

            if(_date.length()!=10){
                throw length_error("Zly format daty");
            }

            if(_date[4]!='-'||_date[7]!='-'){
                throw invalid_argument("Zly format daty");
            }

            for(int i=0;i<_date.length();i++){
                if(i==7||i==4){
                   continue;
                }

                if(!isdigit(_date[i])){
                   throw invalid_argument("Zly format daty");
                }

            }

            auto it = find(_mail.begin(),_mail.end(), '@');
	
  	        if (it == _mail.end()){
                throw invalid_argument("Zly format");
            }
            name=_name;
            nip=_nip;
            date=_date;
            mail=_mail;
        }
};

int main(){
     try {
        Firma firma("aaa", "1234563218", "2025-04-23", "aa@pl");
        cout << "Firma została poprawnie utworzona!" << endl;}
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 0;
}

