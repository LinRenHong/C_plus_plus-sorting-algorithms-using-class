

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HeapSort.h"
using namespace std;


HeapSort::HeapSort( int vectorSize )
{
    size = ( vectorSize > 0 ? vectorSize : 10 );
    srand( time( 0 ) );
    
    data = new string[ size ];
    
    for( int i = 0; i < size; i++ )
    {
        data[ i ] = "";
        for( int j = 0; j < 6; j++ )
        {
            if( rand() % 2 == 0 )
                data[ i ] += (char)( rand() % 26 + 'a' );
            else
                data[ i ] += (char)( rand() % 26 + 'A' );
        }
    }
}

HeapSort::~HeapSort()
{
    delete [] data;
}


void HeapSort::sort()
{
    for( int i = size / 2 - 1; i >= 0; i-- )
        max_heapify( i, size - 1 );
    for( int i = size - 1; i > 0; i-- )
    {
        swap( data[ 0 ], data[ i ] );
        max_heapify( 0, i - 1 );
    }
}


void HeapSort::max_heapify( int start, int end )
{
    int dad = start;
    int son = dad * 2 + 1;
    
    while( son <= end )
    {
        if( son + 1 <= end && data[ son ] < data[ son + 1 ] )
            son++;
        if( data[ dad ] > data[ son ] )
            return;
        else
        {
            swap( data[ dad ], data[ son ] );
            
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


void HeapSort::swap( string &a, string &b )
{
    string temp = a;
    a = b;
    b = temp;
}



void HeapSort::displayElements() const
{
    displaySubVector( 0, size - 1 );
}


void HeapSort::displaySubVector( int low, int high ) const
{

    for( int i = 0; i < low; i++ )
        cout << "   ";


    for( int i = low; i <= high; i++ )
        cout << " " << data[ i ];
}
