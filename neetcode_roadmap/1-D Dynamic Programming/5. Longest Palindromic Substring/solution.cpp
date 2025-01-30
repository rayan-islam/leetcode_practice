class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int lM;
        int rM;
        for(int i=0; i<s.size();i++){
            //odd
            int left=i;
            int right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1>rM-lM+1){
                    rM=right;
                    lM=left;
                }
                left--;
                right++;
            }

            //even
            
            left=i;
            right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1>rM-lM+1){
                    rM=right;
                    lM=left;
                }
                left--;
                right++;
            }

        }
        for(int i=lM; i<=rM;i++){
            ans+=s[i];
        }
        return ans;

    }
};

