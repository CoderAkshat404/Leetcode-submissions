class Solution {
public:
    set<int> s;
    int dp[3001][3001];
    int solve(int i,int j,string&source, string&pattern){
        if(i==source.length()){
            // cout<<j<<endl;
            if(j==pattern.length()){
                return 0;
            }
            else{
                // cout<<"this"<<endl;
                return -1e9;
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        if(s.find(i)!=s.end()){
            ans=max(ans,1+solve(i+1,j,source,pattern));
        }
        if(j<pattern.length() && source[i]==pattern[j])
            ans=max(ans,solve(i+1,j+1,source,pattern));
        ans=max(ans,solve(i+1,j,source,pattern));  
        // cout<<ans<<endl;
        return dp[i][j]=ans;

    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        for(auto i:targetIndices){
            s.insert(i);
        }
        // for(auto i:s){
        //     cout<<i<<" ";
        // }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,source,pattern);
        
    }
};