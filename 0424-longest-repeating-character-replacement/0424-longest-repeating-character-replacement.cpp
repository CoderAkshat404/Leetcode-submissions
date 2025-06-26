class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int r=-1;
        int l=0;
        int ans=0;
        unordered_map<char,int> m;
        int maxf=0;
        
        while(l<n){
            while(r+1<n && ((m[s[r+1]]==maxf &&(r+1-l+1)-(maxf+1)<=k) || (m[s[r+1]]!=maxf &&(r+1-l+1)-(maxf)<=k))){
                r++;
                m[s[r]]++;
                maxf=max(maxf,m[s[r]]);
            }
            ans=max(ans,r-l+1);
        
        if(r<l){
            l++;
            r=l-1;
        }
        else{
            m[s[l]]--;
            maxf=0;
            for(char ch='A';ch<='Z';ch++){
                maxf=max(maxf,m[ch]);
            }
            l++;
        }
        }
    return ans;  
      
    }
    
};