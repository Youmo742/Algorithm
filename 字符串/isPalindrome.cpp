class Solution {
public:
  bool isPalindrome(string s)
    {
         if(s.empty())
             return true;
         string s2="";
         for(auto i=s.begin();i!=s.end();i++)
         {
             if((*i>=65)&&(*i<65+26)||(*i>=97&&*i<97+26)||(*i>='0'&&*i<='9'))
             {

                 s2+=tolower(*i);
             }
         }
         auto t1=s2.begin(),t2=s2.end()-1;
         for(;t1!=t2&&t1<t2;)
         {
             if(*t1++!=*t2--)
                 return false;
         }

         return true;
    }
};
