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
        int posMax = nums[0];
        int negMax = nums[0];
        int ret = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int tempPosMax = posMax;
            int tempNegMax = negMax;
            posMax = max(nums[i],max(nums[i]*tempPosMax,nums[i]*tempNegMax));
            negMax = min(nums[i],min(nums[i]*tempPosMax,nums[i]*tempNegMax));
            ret = max(ret,posMax);
        }
        return ret;
       }
};
#endif // MAXPRODUCT_H
