class Solution {
public:
    int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        #define int long long
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int step=queries[i][2];
            int val=queries[i][3];
            for(int j=start;j<=end;j+=step){
                int x=nums[j]*val;
                x=x%mod;
                nums[j]=x;
            }
        }
        int ans=0;
        for(auto i:nums){
            ans=ans^i;
        }
        return ans;
        #undef int
        
    }
};