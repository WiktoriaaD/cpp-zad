#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

namespace strutil {
    string toUpper(const string &str){
        const int offset=32; //lub 'a' - 'A';
        string out;
        for(int i=0;i<str.length();i++){
            if (str[i]>='a' && str[i]<='z')
            {
                out+=(str[i]-offset);
            }
            else {
                out+=str[i];
            }
        }
        return out;
    }

    string randStr(int length){
        srand(time(NULL));
        string out;
        for(int i=0;i<length;i++){
            char c=97+rand()%26;
            out=out+c;
        }
            return out;
           
    }

    int longestWordLength(const string &str){
        int max=0;
        int current;
        for(int i=0;i<str.length();i++){
            if(str[i]==32){
                if(current>max){
                    max=current;
                }
                current=0;
            
            }else{
                    current++;
                }
        }
        if(current>max)
        {
            max=current;
        }
        return max;
    }
}

int main(){
    int choice=0;
    cout << "Podaj tekst: ";
    string input;
    getline(cin,input);
    int length;
    do
    {
    cout << "Wybierz opcje:\n ";
    cout << "1.Zamien na duze litery:\n";
    cout<<"2.Losuj litery:\n";
    cout<<"3.Zwraca dlugosc najdluzszego slowa:\n";
    cout<< "4. Zakończ program\n";

    cin >> choice;
    if(choice == 1){
        cout<< "Duże litery: ";
        cout << strutil::toUpper(input)<<"\n";
    }
    if(choice == 2){
        cout << "Podaj dlugosc slowa: ";
        cin >> length;
        cout << "Słowo: ";
        cout << strutil::randStr(length) <<"\n";
    }
    if(choice == 3){
        cout<< "Najdluzsze slowo ma liter: ";
        cout << strutil::longestWordLength(input)<<"\n";
    }
    }while (choice!=4);
    return 0;
}

//strutil:toUpper