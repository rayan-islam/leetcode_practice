#include<bits/stdc++.h>

using namespace std;

//best answer

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};


// my answer
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string,string> ans;
        vector<vector<string>> answer;
        for (int i=0; i<strs.size();i++){
             vector<int> key(26);

            fill(key.begin(), key.end(), 0);
            
            for (int j=0; j<strs[i].length();j++){
                key[strs[i][j]-'a']=key[strs[i][j]-'a']+1;
            
            }
            string kee="";
            for(int k=0; k<key.size();k++){
                kee+=to_string(key[k]);
                kee+=",";
            }
            cout<< kee<<endl;
            ans.insert({kee,strs[i]});
        }
        auto it = ans.begin();
        while (it != ans.end()) {
            string key=it->first;
            vector<string> temp;
            while (it != ans.end() && it->first == key) {
                temp.push_back(it->second);
                it++;
            }
            answer.push_back(temp);
        }
        return answer;
    }
};

int main(){
    vector<string> input{"bdddddddddd","bbbbbbbbbbc"};
    Solution s;
    s.groupAnagrams(input);


}