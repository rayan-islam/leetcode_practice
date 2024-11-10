#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int start=0;
        int maxi=1;
        set<char> temp;
        temp.insert(s[0]);

        int i=1;
        while(i<s.length()){
            if(temp.find(s[i])==temp.end()){
                temp.insert(s[i]);
                
            }else{
                temp.erase(s[start]);
                start++;
                continue;
            }
            //cout<<temp.size()<<endl;
            maxi=max((int)temp.size(),maxi);
            i++;
        }
        return maxi;
    }
};

int main(){ 

    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");

}