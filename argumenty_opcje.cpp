#include <iostream>

using namespace std;
int main(int argc, char *argv[]){
    int choice = 0;
    do{
        cout << "Wybierz opcje:\n ";
        cout << "1. Wypisz ilość argumentów programu\n";
        cout << "2. Wypisz wybrany argument programu\n";
        cout << "3. Wypisz wszystkie argumenty programu\n";
        cout<< "4. Zakończ program\n";
        cin >> choice;
        if (choice==1) {
            cout << "Ilosc argumentow podanych: " << argc - 1 << endl;
        }
        if (choice==2) 
        {
            cout << "Podaj wybrany argument: ";
            int i;
            cin >> i;
            if (i>=0 && i<argc) {
                cout <<"Wybrany argument: " << argv[i] <<endl;
            }
            else { 
                cout << "Nie istnieje" <<endl;
            }
        }
        if (choice==3)
        {
            for (int i = 0; i < argc; i++) {
                cout << argv[i] << endl;
            }
        }
    } while (choice!=4);

    return 0;
}