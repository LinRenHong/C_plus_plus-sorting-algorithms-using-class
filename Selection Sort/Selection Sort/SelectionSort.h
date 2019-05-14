


#include <vector>
using namespace std;


class SelectionSort
{
public:
    SelectionSort( int );
    ~SelectionSort();
    void sort();
    void displayElements() const;
private:
    int size;
    string *data;
    void swap( string &, string & );
    void displaySubVector( int, int ) const;
};
