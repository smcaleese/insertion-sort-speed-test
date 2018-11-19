#!/usr/bin/env python

# Note that this test takes about 20 seconds to run
import time

a = []
n = input()

i = 0
while i < 10000:
    a.append(n)
    n = input()
    i = i + 1

def insertionSort():
    i = 1
    while i < len(a):
        v = a[i]
        p = i
        while 0 < p and v < a[p - 1]:
            a[p] = a[p - 1]
            p = p - 1
        a[p] = v
        i = i + 1

start_time = time.time()
insertionSort()
time_taken = str(time.time() - start_time)

print "Time taken to sort 10,000 random numbers using insertion sort: " + time_taken + " seconds"

