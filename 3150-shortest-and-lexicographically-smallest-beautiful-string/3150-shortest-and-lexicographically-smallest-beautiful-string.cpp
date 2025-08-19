class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
    int mini=1e9;
    string ans="";
    int n=s.length();
    int l=0;
    int r=-1;
    int onec=0;
    while(l<n){
        while(r+1<n && onec<k ){
            r++;
            if(s[r]=='1'){
                onec++;
            }
        }
        if(onec==k){
            int len=r-l+1;
            if(len<mini){
                ans=s.substr(l,len);
                mini=len;
            }
            if(len==mini){
                ans=min(ans,s.substr(l,len));
            }
        }
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                if(s[l]=='1'){
                    onec--;
                }
                l++;
            }
        
    }
    return ans;
        
    }
};