

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MergeSort.h"
using namespace std;


MergeSort::MergeSort( int vectorSize )
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

MergeSort::~MergeSort()
{
    delete [] data;
}


void MergeSort::sort()
{
    string *combined = new string[ size ];
    sortSubVector(combined, 0, size - 1);
    delete [] combined;
}


void MergeSort::sortSubVector( string *combined, int low, int high )
{
    if( low >= high )
        return;
    
    int left, middle1, middle2, right;
    left = low;
    middle1 = ( high - low ) / 2 + low;
    middle2 = ( high - low ) / 2 + low + 1;
    right = high;
    
    sortSubVector(combined, left, middle1);
    sortSubVector(combined, middle2, right);
    int combinedIndex = low;
    
    while( left <= middle1 && middle2 <= right )
        combined[ combinedIndex++ ] = data[ left ] < data[ middle2 ] ? data[ left++ ] : data[ middle2++ ];
    while( left <= middle1 )
        combined[ combinedIndex++ ] = data[ left++ ];
    while( middle2 <= right )
        combined[ combinedIndex++ ] = data[ middle2++ ];
    for( combinedIndex = low; combinedIndex <= high; combinedIndex++ )
        data[ combinedIndex ] = combined[ combinedIndex ];
}



void MergeSort::displayElements() const
{
    displaySubVector( 0, size - 1 );
}


void MergeSort::displaySubVector( int low, int high ) const
{

    for( int i = 0; i < low; i++ )
        cout << "   ";


    for( int i = low; i <= high; i++ )
        cout << " " << data[ i ];
}
