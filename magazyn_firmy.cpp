#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Product{
    string name;
    unsigned int price;
    unsigned int qty;
};



void Showproducts(const vector<Product>& products){
    cout << "Magazyn:\n";
    string outtext;
    int i=0;
    for(int size_t = 0; i <products.size();i++){
        cout <<"Nazwa: "<<products[i].name << "\t"<< "Cena: "  << products[i].price << "\t" << "Ilosc: " << products[i].qty <<"\n";
    }
    
}

void Addproduct(vector<Product>& products){
    Product add;
    cout << "Podaj nazwe produktu: ";
    cin>>add.name;
    cout << "Podaj cene produktu: ";
    cin>>add.price;
    cout << "Podaj ilosc produktu: ";
    cin>>add.qty;
    products.push_back(add);
}

void Delproduct(vector<Product>& products){
    string change;
    cout << "Podaj produkt do usuniecia: ";
    cin>>change;
    bool istnieje = false;
    for(int i=0;i<products.size();i++){
        if(products[i].name==change){
            products.erase(products.begin()+i);
            cout << "Produkt zostal usuniety.";
            istnieje = true;
            break;
        }
    }
    if (istnieje == false){
        cout << "Produkt nie istnieje.\n";
    }    
}

void Changeqty(vector<Product>& products){
    string change;
    int newqty;
    cout << "podaj produkt do zmiany ilosci: ";
    cin >> change;
    cout << "Podaj nowa ilosc produktu: ";
    cin >> newqty;
    bool istnieje = false;
    for(int i=0;i<products.size();i++){
        if(products[i].name==change){
            products[i].qty = newqty;
            istnieje = true;
        }
    }
    if (istnieje == false){
        cout << "Produkt nie istnieje.\n";
    }
}

void savetofile(vector<Product>& products){
    ofstream Magazyn;
    Magazyn.open("magazyn.txt");
    for(int i=0;i<products.size();i++){
        Magazyn << products[i].name <<" "<<  products[i].price <<" "<< products[i].qty<<"\n";
    }
    Magazyn.close();
}

void loadfromfile(vector<Product>& products){
    ifstream Magazyn;
    Magazyn.open("magazyn.txt");
    if (Magazyn.good()){
        Product p;
        int i=0;
        while (Magazyn >> p.name >> p.price >> p.qty) {
            products.push_back(p);
        }
        Magazyn.close();
    }
}

void Searchproduct(vector<Product>& products){
    string p;
    cout << "Podaj produkt ktory chcesz wyszukac: ";
    cin >> p;
    bool istnieje = false;
    for(int i=0;i<products.size();i++){
        if(products[i].name==p){
            cout <<"Nazwa: "<<products[i].name << "\t"<< "Cena: "  << products[i].price << "\t" << "Ilosc: " << products[i].qty <<"\n";
            istnieje = true;
        }
    }
    if (istnieje == false){
        cout << "Produkt nie istnieje.\n";
    }
}



int main(){
    int choice=0;
    vector<Product> products;
    loadfromfile(products);
    do{
        cout << "\nWybierz opcje:\n";
        cout << "1. Wyswietl spis wszystkich produktow.\n";
        cout << "2. Dodaj produkt.\n";
        cout << "3. Usun produkt.\n";        
        cout << "4. Zmień ilość produktu.\n";
        cout<< "5. Wyszukaj produkt po nazwie.\n";
        cout<< "6. Zakończ program.\n";
        cin >> choice;
        if (choice==1){
            Showproducts(products);
        }
        else if(choice==2)
        {
            Addproduct(products);
        }
        else if(choice==3)
        {
            Delproduct(products);
        }       
        else if(choice==4)
        {
            Changeqty(products);
        }
        else if(choice==5)
        {
            Searchproduct(products);
        }
        savetofile(products);
    }while (choice!=6);
    return 0;
}