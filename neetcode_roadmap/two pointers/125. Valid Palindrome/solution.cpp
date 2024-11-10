#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0; i<s.length();i++){
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122||s[i]>=48 && s[i]<=57){
                if(s[i]>=65 && s[i]<=90){
                    ans+=tolower(s[i]);
                }
                else{
                    ans+=s[i];
                }
            }
        }

        //cout<<ans;

        if(s.length()==0){
            return true;
        }
        int l=0;
        int r=ans.length()-1;
        for(int i=0;i<ans.length()/2;i++){
            if(ans[l]!=ans[r]){
                //cout<<i;
                return false;
            }
            l++;
            r--;
        }      
        return true;
    }
};

int main(){
    Solution s;
    string ss="A man, a plan, a canal: Panama";
    s.isPalindrome(ss);
}