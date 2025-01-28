class Solution {
public:
    bool static cmp(string a,string b){
        return a.length()<b.length();
    }
    bool check(string a,string b){
        if(a.size()!=b.size()+1){
            return false;
        }
        int i=0;
        int j=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(i==a.size() && j==b.size()){
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int maxi=INT_MIN;
        vector<int> dp(words.size(),1);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
                
            }
            maxi=max(maxi,dp[i]);

        }
     return maxi;   
    }
};