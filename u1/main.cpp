/// Compiled with clang -std=c++11 -lstdc++ main.cpp -o u1

#include <vector>
#include <chrono>
#include <iostream>
#include <list>
#include <random>

std::vector<int> containerV;
std::list<int> containerL;
constexpr unsigned int max_size = 1000000;

int randint(int min, int max)
{
    static std::default_random_engine ran;
    const std::chrono::high_resolution_clock::duration d = std::chrono::high_resolution_clock::now().time_since_epoch();
    ran.seed({static_cast<unsigned int>(d.count())});
    return std::uniform_int_distribution<>{min,max}(ran);
}

void insertVector(int size) {
	const auto start = std::chrono::system_clock::now();
	for (int i = 0; i < size; ++i) {
		const int n = randint(0, size);
		const auto it = std::lower_bound(containerV.begin(), containerV.end(), n);
		containerV.insert(it, n);
	}
	const auto stop = std::chrono::system_clock::now();
	const auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
	std::cout << time << "ns\t";
}


void insertList(int size) {
	const auto start = std::chrono::system_clock::now();
	for (int i = 0; i < size; ++i) {
		const int n = randint(0, size);
		const auto it = std::lower_bound(containerL.begin(), containerL.end(), n);
		containerL.insert(it, n);
	}
	const auto stop = std::chrono::system_clock::now();
	const auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
	std::cout << ":\t" << time << "ns\n";
}

int main() {
	
	
	for(unsigned int size = 2; size < max_size; size += 2)
	{
	    insertVector(size);
	    insertList(size);
	}
	return 0;
}
