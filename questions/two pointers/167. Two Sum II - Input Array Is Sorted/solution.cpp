#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> t;
        int left=0;
        int right = numbers.size()-1;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[left]+numbers[right]>target){
                right--;
            }else if(numbers[left]+numbers[right]<target){
                left++;
            }else{
                if(right!=left){
                    t.push_back(left+1);
                    t.push_back(right+1);
                    return t;
                }
            }

        }
        vector<int> t1{0,0};
        return t1;
    }
};

int main (){
    vector<int> a;

    Solution ss;


    
}