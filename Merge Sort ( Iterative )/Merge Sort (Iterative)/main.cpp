//
//  main.cpp
//  Merge Sort (Iterative)
//
//  Created by 林仁鴻 on 2018/3/19.
//  Copyright © 2018年 林仁鴻. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "MergeSort.h"

using namespace std;

int main()
{
    ofstream output( "SpendTime.txt" );
    int size;
    clock_t start, end;
    double cpu_time_used;
    
    cin >> size;
    MergeSort sortVector( size );

    cout << "Unsorted vector:" << endl;
    sortVector.displayElements();
    cout << endl << endl;
    
    start = clock();
    sortVector.sort();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    cout << "Time = " << cpu_time_used << endl;
    sortVector.displayElements();
    
//    cout << "Sorted vector:" << endl;
//    sortVector.displayElements();
//    cout << endl;
    output.close();
}
