#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> ans;
        vector<pair<int,int>> temp;
        
        for(int i=0; i<position.size();i++){
            temp.push_back(make_pair(position[i],speed[i]));
        }
        sort(temp.begin(),temp.end());
        for(auto x: temp){
            cout<< x.first<<" "<<x.second<<endl;
        }

        ans.push(temp[position.size()-1]);
        for(int i=position.size()-2;i>=0;i--){
            pair<int,int> top=ans.top();
            //cout<<top.first<<"  "<<top.second<<endl;
            float tslope=1.0*(target-top.first)/top.second;
            //cout<<temp[i].first<<"  "<<temp[i].second<<endl;
            float aslope=1.0*(target-temp[i].first)/temp[i].second;
            // cout<<tslope<< " "<<aslope<<endl;
            
            if(tslope<aslope){
                ans.push(make_pair(temp[i].first,temp[i].second));
            }else{
                continue;
            }
        }
        return ans.size();
    }
};

int main(){
    Solution s;
    vector<int> a1{10,8,0,5,3};
    vector<int> a2{2,4,1,1,3};
    int target=12;
    s.carFleet(target,a1,a2);

}