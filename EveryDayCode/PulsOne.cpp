#include <iostream>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int>& digits) 
{
    //   vector<int> result;
      for(int i=digits.size()-1;i>=0;i--)
      {
          if(digits[i]+1==10)
          {
              digits[i]=0;
              if(i==0)
              {
                //   result.push_back(1);
                digits.insert(digits.begin(),1);
              }
          }
          else
          {
              digits[i]=digits[i]+1;
              break;
          }  
      } 
    //   for(auto i:digits)
        // result.push_back(i); 
      return digits;
}
int main()
{
    vector<int> v({9,9,9});
    // vector<int> res=plusOne(v);
    plusOne(v);
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}