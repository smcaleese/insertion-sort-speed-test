#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

int num_tests = 5;
const int max_length = 10000;
int list[max_length];

void read()
{
    ifstream fin("ten-thousand-random-numbers.txt");
    for (int x = 0; x < max_length; x++) {
        fin >> list[x];
    }
    fin.close();
}

void insertionSort() {
    unsigned int i = 1;
    while(i < sizeof(list) / sizeof(list[0]) ) {
        int v = list[i];
        int p = i;
        while( 0 < p and v < list[p - 1] ) {
            list[p] = list[p - 1];
            p = p - 1;
        }
        list[p] = v;
        i++;
    }
}

int main()
{
    double t1, t2, time_taken, sum, average_time;
    sum = 0;

    for(int j = 1; j <= num_tests; j++) {
        read();
        t1 = clock();
        insertionSort();
        t2 = clock();
        time_taken = (t2 - t1) / CLK_TCK;
        cout << "Test " << j << ":" << " time taken to sort 10,000 random numbers using insertion sort: " << time_taken << " sec\n";
        sum = sum + time_taken;
    }

    average_time = sum / num_tests;

    string short_average_time = to_string(average_time);
    cout << "Average time taken taken: " << short_average_time.substr(0, 5) << " sec" << endl;

    return 0;
}
