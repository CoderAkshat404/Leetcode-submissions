class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int> m;
            for(int j=i;j<n;j++){
                m[s[j]]++;
                int mini=1e9;
                int maxi=0;
                for(auto ch:m){
                    mini=min(mini,ch.second);
                    maxi=max(maxi,ch.second);
                }
                if(maxi-mini>0){
                    ans+=maxi-mini;
                }
            }
        }
        return ans;
        
    }
};