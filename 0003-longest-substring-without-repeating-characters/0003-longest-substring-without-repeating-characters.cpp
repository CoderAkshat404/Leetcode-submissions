class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        int l=0;
        int r=-1;
        int ans=0;
        while(l<n){
            while(r+1<n &&  m[s[r+1]]==0){
                r++;
                m[s[r]]++;
            }
            ans=max(ans,r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                m[s[l]]--;
                l++;
            }

        }
        return ans;
        
    }
};