//
//  main.cpp
//  Collatz Conjecture
//
//  Created by user on 11/4/15.
//  Copyright (c) 2015 Ben Dahl. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// returns the number of iterations in collatz conjucture
int collatz(unsigned long long int n);

int main() {
    int num;
    pair<int,int> numPair, maxIter;
    vector<pair<int,int>> numIter;
    
    cout << "Collatz Conjecture" << endl;
    
    cout << "Enter an int: ";
    cin >> num;
    
    cout << "Number\t:\tIterations" << endl;
    for (int i = 1; i <= num; i++)
    {
        numPair = pair<int,int>(collatz(i),i);
        numIter.push_back(numPair);
        cout << i << "\t:\t" << numIter[i-1].first<< endl;
    }
    
    maxIter = * max_element(numIter.begin(),numIter.end());
    
    cout << endl << "Value with Max number of iterations: " << maxIter.second << "\t:\t" << maxIter.first << endl;
    
    
    return 0;
}


int collatz(unsigned long long int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n%2 == 0)
        n /= 2;
    else
        n = n * 3 + 1;
    
    return 1 + collatz(n);
}