class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        for(int i=0; i<s.size();i++){
            //for odd length palindrom
            
            int left =i;
            int right =i;
            while(left>=0 && right<=s.size() && s[left]== s[right]){
                result++;
                left--;
                right++;
            }
            //for even length palindrom
            
            left =i;
            right =i+1;
            while(left>=0 && right<=s.size() && s[left]== s[right]){
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};
