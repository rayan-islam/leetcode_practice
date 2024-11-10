#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()==0)
            return 0;

        int count[26];
        for( int i=0; i<26;i++){
            count[i]=0;
        }
        int l=0,r=0,result=0;

        int maximum=0;

        while(r<s.length()){
            
            count[int(s[r])-65]++;

            //cout<<maximum<<endl;
            //cout<<"--------------------count--------------------"<<endl;

            for(int i=0; i<26; i++){

               // cout<<count[i]<<endl;
                maximum=max(maximum,count[i]);
            }
            
           // cout<<maximum<<endl;

            while(r-l+1 - maximum >k){
                count[int(s[l])-65]--;
                l++;
            }
            
            result=max(result,r-l+1);
            
            r++;
        }
        return result;
    }
};

int main(){
    string s="AABABBA";
    int k=1;
    Solution ss;
    int result=ss.characterReplacement(s,k);
    cout<<result<<endl;

}