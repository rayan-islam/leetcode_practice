#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int l=0;
        int r=height.size()-1;
        int temp;
        for(int i=0; i<height.size();i++){
            temp=min(height[l],height[r])*(r-l);
            area=max(area,temp);
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        return area;
    }
};

int main(){

}