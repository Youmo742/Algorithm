#ifndef MAXPRODUCT_H
#define MAXPRODUCT_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）
*/
    int maxProduct(vector<int>& nums)
    {
        vector<int> v;
        v.clear();


        for(int t=0;t<nums.size();t++)
        {
            v.push_back(nums[t]);
            v.push_back(v.back()*nums[t]);
        }
        sort(v.begin(),v.end());
        return v.back();
    }
};
#endif // MAXPRODUCT_H
