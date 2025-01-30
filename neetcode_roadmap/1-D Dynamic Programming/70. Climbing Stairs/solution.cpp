class Solution {
public:
    int climbWay(int n,vector<int>& arr){
        if(arr[n-1]!=0){
            return arr[n-1];
        }
        if(arr[n-2]!=0 && arr[n-3]!=0){
            arr[n-1]=arr[n-2]+arr[n-3];
            return arr[n-1];
        }
        arr[n-1]= climbWay(n-1,arr)+climbWay(n-2,arr);
        return arr[n-1];
    }
    int climbStairs(int n) {
        vector<int> climb(n,0);
        climb[0]=1;
        if(n>1)
            climb[1]=2;

        return climbWay(n,climb);
    }
};
