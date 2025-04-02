#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
using namespace std;


class TimeMeasurement
{
	std::string name;
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	
public:
	TimeMeasurement(std::string _name) : name(_name) {
		start = std::chrono::high_resolution_clock::now();
	}
	
	~TimeMeasurement() {
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		std::cout << name << ": " << duration.count() << " sec" << std::endl;
	}
};


int main()
{
	const int N=100000;
	
	{
		TimeMeasurement t("Dodawanie elementow na poczatek w wektorze");
		vector<int> vect;
		for (int i = 0; i < N; i++){
			vect.insert(vect.begin(),123456);
		}
		
	}

	{
		TimeMeasurement t("Dodawanie elementow na poczatek w liscie");
		list<int> lista;
		for (int i = 0; i < N; i++){
			lista.insert(lista.begin(),123456);
		}
		
	}
	
	{
		vector<int> vect;
		vect.reserve(N);
		for (int i = 0; i < N; i++){
			vect.push_back(i);
		}
		TimeMeasurement t("sumowanie elementow wektora");
		int suma = 0;
		for (int i = 0; i < N; i++){
			suma += vect[i];
		}
		
	}

	{
		list<int> lista;
		for (int i = 0; i < N; i++){
			lista.push_back(i);
		}
		{
		TimeMeasurement t("sumowanie elementow listy");
		int suma = 0;
		for(auto i = lista.begin(); i != lista.end(); i++)
			suma += *i;
		}
	}

	return 0;
}