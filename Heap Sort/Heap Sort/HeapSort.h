


#include <vector>
using namespace std;


class HeapSort
{
public:
    HeapSort( int );
    ~HeapSort();
    void sort();
    void displayElements() const;
private:
    int size;
    string *data;
    void max_heapify( int, int );
    void swap( string &, string & );
    void displaySubVector( int, int ) const;
};
