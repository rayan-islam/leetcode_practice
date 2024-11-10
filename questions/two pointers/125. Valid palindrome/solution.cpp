#include<bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string test="";
        for(int i=0; i<s.length();i++){
            if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122)||(s[i]>=48 && s[i]<=57)){
                //cout<<"in "<<i<<endl;
                test+=tolower(s[i]);
            }
        }
        //cout<<test<<endl;
        if(test.length()==0){
            return true;
        }
        int first=0;
        int last=test.length()-1;
        for(int i=0; i<test.length()/2;i++){
            if(test[first]!=test[last]){
                return false;
            }
            first++;
            last--;
        }    
        return true;
    }
};


int main(){
    string s;
    getline(cin,s);
    //cout <<s<<endl;
    Solution ss;
    if(ss.isPalindrome(s)){
        cout<<"Palindrom "<<endl;
    }
    else{
        cout<<"Not a Palindrom "<<endl;
    }
}