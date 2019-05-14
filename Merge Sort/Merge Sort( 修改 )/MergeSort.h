



using namespace std;


class MergeSort
{
public:
    MergeSort( int );
    ~MergeSort();
    void sort();
    void sortSubVector( string *, int, int );
    void displayElements() const;
private:
    int size;
    string *data;
    void displaySubVector( int, int ) const;
};
