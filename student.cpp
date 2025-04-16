#include <iostream>
#include "json.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


using json = nlohmann::json;

struct Student {
    int id;
    string firstName;
    float score;
    string lastName;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, id, firstName,lastName,score)

    string calcGrade() const{
        if (score >= 90) return "5";
        else if (score >= 80) return "4+";
        else if (score >= 70) return "4";
        else if (score >= 60) return "3+";
        else if(score>=50) return "3";
        else return "2";
    }
};

void dump(const vector<Student>& v) {
    ofstream Studenci;
    json data = v;
    Studenci.open("studenci.json");
    Studenci << data.dump(4) << endl;
};

void sort(vector<Student>& v){
    sort(v.begin(),v.end(), [] (const Student& a,const Student&b){
        return a.calcGrade()>b.calcGrade();
    });
}

void FindbyID(vector<Student>& v,int id){
    auto it = find_if(v.begin(),v.end(), [id](const Student& student){
        return student.id == id;
    });

    if (it != v.end()){
        const Student& student = *it;
        cout << student.id << " || " << student.firstName << " " <<  student.lastName << " | " <<  student.score<< " | "<<student.calcGrade()<<endl;
    } else {
        cout<< "Student nie istnieje" <<endl;
    }

}

void CalcAverage(vector<Student>& v){
    double suma = accumulate(v.begin(),v.end(),0,[](double sum,const Student& v){
        return sum + v.score;
    });

    return suma/v.size();
}

void parse(vector<Student>& v) {
    ifstream Studenci;
    Studenci.open("studenci.json");
    if (Studenci.good()){
        stringstream buffer;
        buffer << Studenci.rdbuf();
        string str = buffer.str();
        json data = json::parse(buffer.str());
        v = data;
        };

}

int main()
{
    vector<Student> v;
    parse(v);
    // sort(v);
    // for (const auto &item : v)
    // {
    //     cout << item.id << " || " << item.firstName << " " <<  item.lastName << " | " <<  item.score<< " | "<<item.calcGrade()<<endl;
    // }
    // dump(v);
    FindbyID(v,23214);
    CalcAverage(v);
    return 0;
}