#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        vector<int> aa(2);
        while(l!=r){
            if(numbers[l]+numbers[r]>target){
                r--;
            }else if(numbers[l]+numbers[r]<target){
                l++;
            }else{
                //cout<<"here";
                vector<int> a;
                a.push_back(l+1);
                a.push_back(r+1);
                return a;
            }
        }
        return aa;
    }
};

int main(){
    vector<int> input{2,7,11,15};
    Solution s;
    vector<int> a=s.twoSum(input,9);
    for(auto x:a){
        cout<< x<<endl;
    }
}