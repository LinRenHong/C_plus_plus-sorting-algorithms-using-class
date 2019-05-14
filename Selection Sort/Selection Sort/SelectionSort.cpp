

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SelectionSort.h"
using namespace std;


SelectionSort::SelectionSort( int vectorSize )
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

SelectionSort::~SelectionSort()
{
    delete [] data;
}


void SelectionSort::sort()
{
    for ( int j = 0; j < size -  1; j++ )
    {
        
        int min = j;
        
        for ( int i = j + 1; i < size; i++ )
        {
            if ( data[ i ] < data[ min ] )
                min = i;
        }
        
        if ( min!= j )
            swap( data[ j ], data[ min ] );
    }
}




void SelectionSort::swap( string &a, string &b )
{
    string temp = a;
    a = b;
    b = temp;
}



void SelectionSort::displayElements() const
{
    displaySubVector( 0, size - 1 );
}


void SelectionSort::displaySubVector( int low, int high ) const
{

    for( int i = 0; i < low; i++ )
        cout << "   ";


    for( int i = low; i <= high; i++ )
        cout << " " << data[ i ];
}
