class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
    int n=s.length();
	int m=t.length();
	vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(s[i]==t[j]){
				dp[i][j]=1+dp[i+1][j+1];
			}
			else{
				dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
    string ans="";
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            ans+=s[i];
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            ans+=s[i];
            i++;
        }
        else{
            ans+=t[j];
            j++;
        }
    }
    while(i<n){
        ans+=s[i];
        i++;
    }
    while(j<m){
        ans+=t[j];
        j++;
    }
    return ans;
	
        
    }
};