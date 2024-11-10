class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if(len(s)<len(t)):
            return ""
        if(s==t):
            return s
        
        t_dict = {}
        for i in range(len(t)):
            t_dict[t[i]] = t_dict.get(t[i],0)+1
        
        print(t_dict)

        left = 0
        right = 0

        min_len = float('inf')
        ans 
        count = len(t)
        s_dict = {}
        valid=False
        while(right<len(s)):
            
            if(s[right] in t_dict):
                s_dict[s[right]]=s_dict.get(s[right],0)+1
                if(s_dict[s[right]]<=t_dict[s[right]]):
                    count-=1
                if(count == 0):
                    valid=True
                    if(right-left+1<min_len):
                        ans=s[left:right]
                
            right+=1
            while(valid):
                if(s[left] in t_dict):
                    s_dict[s[left]]=s_dict.get(s[left],0)-1
                    count+=1
                    valid=False
                left+=1
        return ans