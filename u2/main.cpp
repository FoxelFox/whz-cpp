#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    constexpr unsigned rows = 10000;
    constexpr unsigned columns = 10000;
    auto a = new char[rows][columns];



    auto start = std::chrono::system_clock::now();

    long long sum = 0;
    for (unsigned r = 0; r < rows; ++r) {
        for (unsigned c = 0; c < columns; ++c) {
            //sum += a[r][c];
            sum += a[(r*columns)+c];
        }
    }

    auto stop = std::chrono::system_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << time << "ns\n";


    start = std::chrono::system_clock::now();

    // Reihenfolge vertauscht: aeussere Schleife: Spalten; innere Schleife: Zeilen
    for (unsigned c = 0; c < columns; ++c) {
            for (unsigned r = 0; r < rows; ++r) {
            //sum += a[r][c];
            sum += a[(r*columns)+c];
        }
    }
    stop = std::chrono::system_clock::now();
    time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << time << "ns\n";

    return 0;
}

