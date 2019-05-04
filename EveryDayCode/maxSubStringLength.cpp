#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maxSubStringLength(string s)
    {
        int index[256]={0};
        int left=0;
        int length=0;
        for(int i=0;i<s.size();i++)
        {
            if(index[s[i]]==0||index[s[i]]<left)
            {
                length=max(length,i-left+1);
            }
            else
            {
                left=index[s[i]];
            }
            index[s[i]]=i+1;
        }
        return length;
    }
};
int main()
{
    string s="tmmzuxt";
    cout<<Solution().maxSubStringLength(s)<<endl;
    return 0;
}