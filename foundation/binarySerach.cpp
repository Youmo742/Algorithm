#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;

template<typename type_value> class BinarySerach{
private:
    vector<type_value> arrays;
public:
    BinarySerach(){
        arrays=vector<type_value>();
    }
    BinarySerach(initializer_list<type_value> a){
        arrays=vector<type_value>(a);
    }
    int serach(type_value value){
        std::sort(arrays.begin(),arrays.end());
        return innerserach(0,arrays.size()-1,value);
    }
    ~BinarySerach(){
        arrays.clear();
    }
private:
    int innerserach(int begin, int end, type_value value){
        if (begin >= end)
            return -1;
        int mid = (end - begin) / 2;
        if (arrays[mid] == value)
            return mid;
        else if (arrays[mid] < value)
            return innerserach(mid, end, value);
        else
            return innerserach(begin, mid, value);
    }
};
int main()
{
    // int a[] = {3, 4, 5, 1, 2, 6, 9, 8};
    BinarySerach<int> v({3, 4, 5, 1, 2, 6, 9, 8});
    cout<<v.serach(5)<<endl;
    return 0;
}