#!/usr/bin/env python

# Note that this test takes about 20 seconds to run
import time

num_tests = 5

a = []
n = input()
i = 0
while i < 10000:
    a.append(n)
    n = input()
    i = i + 1

def insertionSort(arr):
    i = 1
    while i < len(arr):
        v = arr[i]
        p = i
        while 0 < p and v < arr[p - 1]:
            arr[p] = arr[p - 1]
            p = p - 1
        arr[p] = v
        i = i + 1

b = []
total = 0
x = 1
while x <= num_tests:
    b = a[:]  # passes by value instead of by reference which is the default
    start_time = time.time()
    insertionSort(b)
    time_taken = time.time() - start_time
    print "Test " + str(x) + \
          ": Time taken to sort 10,000 random numbers using insertion sort: " + \
          str(time_taken) + " seconds"
    total = total + time_taken
    x = x + 1

average = total / num_tests
print "Average time taken: " + str(average) + " seconds"


