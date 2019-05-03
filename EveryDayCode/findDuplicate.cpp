/*
不修改数组，找到重复的元素
剑指offer
*/
#include <iostream>
#include <string>

using namespace std;

// 1.0
// 用辅助数组的方式，统计每个数字出现的次数
// 如果大于1，则返回这个数字

// 2.0
// 采用分治思想，将数组元素按中间的数字划分
// 分别计算中间元素左边的元素个数和右边的元素个数
// 某一边元素个数大于中间元素的值，则重复的元素就在某一个区间内
int getCount(const int numbers[],int length,int start,int end)
{
    if(numbers==nullptr)
        return 0;
    int count=0;
    for(int i=0;i<length;i++)
    {
        if(numbers[i]>=start&&numbers[i]<=end)
            count++;
    }
    return count;
}
int getDuplicate(const int numbers[],int length)
{
    if(numbers==nullptr)
        return -1;
    int start=1;
    int end=length-1;
    while(end>=start)
    {
        int middle=((end-start)>>1)+start;
        int count=getCount(numbers,length,start,middle);
        if(end==start)
        {
            if(count>1)
                return start;
            else
                break;
        }
        if(count>(middle-start+1))
            end=middle;
        else
            start=middle+1;
    }
    return -1;
}
int main()
{
    int numbers[8]={1,2,7,3,4,5,6,6};
    cout<<getDuplicate(numbers,8)<<" ";
    return 0;
}