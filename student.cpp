#include <iostream>
#include "json.hpp"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


using json = nlohmann::json;

struct Student {
    int id;
    string firstName;
    float score;
    string lastName;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, id, firstName,lastName,score)
};

void dump(const vector<Student>& v) {
    ofstream Studenci;
    json data = v;
    Studenci.open("studenci.json");
    Studenci << data.dump(4) << endl;
};

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

    for (const auto &item : v)
    {
        cout << item.id << " || " << item.firstName << " " <<  item.lastName << " | " <<  item.score<<endl;
    }
}

int main()
{
    vector<Student> v;
    parse(v);
    dump(v);
    return 0;
}