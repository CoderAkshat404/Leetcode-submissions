class Solution {
public:
    bool check(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        if(n!=m+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return (i==n && j==m) ||(i==n-1 && j==m);

    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
    return a.size() < b.size();
});

        int n=words.size();
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
        int maxi=INT_MIN;
        for(auto i:dp){
            maxi=max(maxi,i);
        }
        return maxi;
        
    }
};