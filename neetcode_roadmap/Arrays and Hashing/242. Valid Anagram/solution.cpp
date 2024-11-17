#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for ( int i=0; i<s.length();i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
        
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> s_map,t_map;
        for(auto x: s){
            if(s_map.find(x)==s_map.end()){
                s_map[x]=1;
            }else{
                s_map[x]++;
            }
        }
        for(auto x: t){
            if(t_map.find(x)==t_map.end()){
                t_map[x]=1;
            }else{
                t_map[x]++;
            }
        }

        if(t_map.size()!=s_map.size()){
            return false;
        }
        for(auto x:s_map){
            if(s_map[x.first]!=t_map[x.first])
                return false;
        }

        return true;


    }
};
