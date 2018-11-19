#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

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
    double t1, t2;

    for(unsigned int j = 1; j <= 3; j++) {
        read();
        t1 = clock();
        insertionSort();
        t2 = clock();
        cout << "Test " << j << ":" << " time taken to sort 10,000 random numbers using insertion sort: " << (t2 - t1)/CLK_TCK << " sec\n";
    }

    return 0;
}
