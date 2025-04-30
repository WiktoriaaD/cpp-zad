#include <iostream>
#include <numeric>
#include "Ulamek.hpp"
using namespace std;

Ulamek::Ulamek(int a,int b){
    this->a=a;
    this->b=b;
    optimize();
}

void Ulamek::optimize(){
    int gcd = std::gcd(a,b);
    a=a/gcd;
    b=b/gcd;
}

Ulamek Ulamek::operator+(const Ulamek& other) const {
    int new_a = (this->a * other.b) + (other.a * this->b);
    int new_b = this->b * other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator-(const Ulamek& other) const {
    int new_a = (this->a * other.b) - (other.a * this->b);
    int new_b = this->b * other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator*(const Ulamek& other) const {
    int new_a = (this->a * other.a);
    int new_b = this->b*other.b;
    return Ulamek(new_a, new_b);
}

Ulamek Ulamek::operator/(const Ulamek& other) const {
    int new_a = (this->a*other.b);
    int new_b = this->b*other.a;
    return Ulamek(new_a, new_b);
}
bool Ulamek::operator==(const Ulamek& other) const{
    return this->a==other.a||this->b==other.b;
};


int main(){
    Ulamek u1(2,3);
    Ulamek u2(4,7);
    Ulamek sum = u1+u2;
    Ulamek min = u1-u2;
    Ulamek mul = u1*u2;
    Ulamek div = u1/u2;
    bool eq = u1==u2;

    cout<<sum<<endl;
    cout<<min<<endl;
    cout<<mul<<endl;
    cout<<div<<endl;
    cout<<(eq ? "True" : "False")<<endl;

    return 0;
}



