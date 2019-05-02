/*
一个长度为n的数组中，数的范围为0--n-1。
找出一个数组中重复的元素，不止一个，找出一个即可
*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 1.0
// 用hash的方法，因为每一个元素都在0-n-1范围内，一个N大小的数组即可
// 若元素不在，就将数组中位置智1，否则为0
// 需要额外O(n)的存储空间，可以将所有重复元素找出来
int getDuplicate1_0(int numbers[],int length)
{
    int count[length];
    for(int i=0;i<length;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<length;i++)
    {
        if(count[numbers[i]]==0)
            count[numbers[i]]=1;
        else
        {
            return numbers[i];
        }
        
    }
    return -1;
}

// 1.1
// 对所有的元素排序，判断是否重复
// 元素排序后，只需要判断相邻两个是否重复即可
// O(nlgn)
int cmp ( const void *a , const void *b)
{
        return *(int *)b - *(int *)a;
}
int getDuplicate1_1(int numbers[],int length)
{
    if(numbers==nullptr)
        return -1;
    qsort(numbers,length,sizeof(int),cmp);
    int i=0,j=1;
    for(;i<length;)
    {
        if(numbers[i]==numbers[j])
            return numbers[i];
        i++;
        j++;
    }
    return -1;
}

// 1.2
int getDuplicate1_2(int numbers[],int length)
{
    for(int i=0;i<length;i++)
    {
        while(numbers[i]!=i)
        {
            if(numbers[i]==numbers[numbers[i]])
                return numbers[i];
            int temp=numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }
    }
    return -1;
}
int main()
{
    int numbers[8]={1,2,3,3,4,5,6,6};
    cout<<getDuplicate1_0(numbers,8)<<" ";
    cout<<getDuplicate1_1(numbers,8)<<" ";
    cout<<getDuplicate1_2(numbers,8)<<" ";
    return 0;
}