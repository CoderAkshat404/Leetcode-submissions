class Solution {
public:
    void solve(int i,vector<int>& nums,int &ans,int xori){
        if(i>=nums.size()){
            ans+=xori;
            return;
        }
        xori=xori^nums[i];
        solve(i+1,nums,ans,xori);
        xori=xori^nums[i];
        solve(i+1,nums,ans,xori);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        solve(0,nums,ans,0);
        return ans;
        
    }
};