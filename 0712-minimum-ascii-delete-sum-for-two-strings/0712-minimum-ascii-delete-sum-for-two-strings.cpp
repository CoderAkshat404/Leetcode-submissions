class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string&s1, string&s2){
        if(i>=s1.length()){
            int x=0;
            for(int k=j;k<s2.length();k++){
                x+=s2[k];
            }
            return x;
            
        }
        if(j>=s2.length()){
            int x=0;
            for(int k=i;k<s1.length();k++){
                x+=s1[k];
            }
            return x;

        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans= solve(i+1,j+1,s1,s2);
        }
        else{
            ans=min(int(s1[i])+solve(i+1,j,s1,s2),int(s2[j])+solve(i,j+1,s1,s2)); 
        }
        return dp[i][j]=ans;

    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int l=solve(0,0,s1,s2);
        return l;



        
    }
};