#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right =height.size()-1;
        int area=0;
        int temp;
        for(int i=0; i<height.size();i++){
            temp=(right-left)*min(height[left],height[right]);
            area = max(area,temp);
            if(height[left]>=height[right]){
                right--;
            }else{
                left++;
            }
        }
        return area;
    }
};

int main (){
    vector<int> a;

    Solution ss;


    
}