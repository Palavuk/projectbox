#include <fstream>
#include <random>
#include <algorithm>
#include <iostream>
#include "vec.h"

using namespace std;

int main(){
	Vector<ofstream> streams;
	streams.push_back(ofstream("a.txt"));
	streams.push_back(ofstream("b.txt"));
	streams.push_back(ofstream("c.txt"));

	std::random_device rand;
	std::mt19937 gen(rand());
	std::shuffle(streams.begin(), streams.end(), gen);

	for (int i = 0; i < 3; i++) {
		streams[i] << i + 1;
		cout << i + 1;
	}
		
	
	return 0;
}