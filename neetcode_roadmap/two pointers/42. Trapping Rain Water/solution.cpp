#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> maxleft(height.size(),0);
        vector<int> maxright(height.size(),0);
        int tempMaxLeft;
        for(int i=1; i<height.size();i++){
            maxleft[i]=max(height[i-1],maxleft[i-1]);
            maxright[height.size()-1-i]=max(height[height.size()-i],maxright[height.size()-i]);        
        }
        int store=0;
        for( int i=0; i<height.size();i++){
            store+=max(min(maxleft[i],maxright[i])-height[i],0);
        }

        return store;
    }
};


int main(){
    vector<int> input{0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;
    cout<<s.trap(input);

}