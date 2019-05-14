

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
    int left, middle1, middle2, right, combinedIndex;
 
    for( int i = 1; i < size; i *= 2 )
    {
        for( int j = 0; j < size; j += 2 * i )
        {
            left = j;
            combinedIndex = left;
            middle1 = min( j + i, size );
            middle2 = min( j + i, size );
            right = min( j + 2 * i, size );
            
            while( left < middle1 && middle2 < right )
                combined[ combinedIndex++ ] = data[ left ] < data[ middle2 ] ? data[ left++ ] : data[ middle2++ ];
            while( left < middle1 )
                combined[ combinedIndex++ ] = data[ left++ ];
            while( middle2 < right )
                combined[ combinedIndex++ ] = data[ middle2++ ];
        }
        string *temp = data;
        data = combined;
        combined = temp;
    }
    delete [] combined;
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
