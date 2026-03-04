class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<vector<int>>& offers){
        if(i==offers.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake=solve(i+1,offers);
        int nxtidx=offers.size();
        int lo=i+1;
        int hi=nxtidx-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(offers[mid][0]>offers[i][1]){
                nxtidx=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        int take=offers[i][2]+solve(nxtidx,offers);
        return dp[i]=max(take,nottake);
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        dp.resize(offers.size(),-1);
        return solve(0,offers);
        
    }
};