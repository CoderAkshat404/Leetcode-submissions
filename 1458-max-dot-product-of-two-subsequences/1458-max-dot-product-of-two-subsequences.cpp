class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=-1e9;
        maxi=max(maxi,solve(i+1,j,nums1,nums2));
        maxi=max(maxi,solve(i,j+1,nums1,nums2));
        maxi=max(maxi,solve(i+1,j+1,nums1,nums2));
        maxi=max(maxi,nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2));
        maxi=max(maxi,nums1[i]*nums2[j]);
        return dp[i][j]=maxi;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // int cntposi1=0;
        // int cntnegi1=0;
        // for(auto i:nums1){
        //     if(i>=0){
        //         cntposi1++;

        //     }
        //     else{
        //         cntnegi1++;
        //     }
        // }
        // int cntposi2=0;
        // int cntnegi2=0;
        // for(auto i:nums2){
        //     if(i>=0){
        //         cntposi2++;

        //     }
        //     else{
        //         cntnegi2++;
        //     }
        // }
        
        // if((cntposi1==0 && cntposi2==nums2.size()) || (cntnegi1==0 && cntnegi2==nums2.size())){
        //     if(nums1[0]<0){
        //         sort(nums1.rbegin(),nums1.rend());
        //         sort(nums2.begin(),nums2.end());
        //         return nums1[0]*nums2[0];
        //     }
        //     else{
        //         sort(nums2.rbegin(),nums2.rend());
        //         sort(nums1.begin(),nums1.end());
        //         return nums1[0]*nums2[0];

        //     }
        // }
        memset(dp,-1,sizeof(dp));
       return  solve(0,0,nums1,nums2);
        
    }
};