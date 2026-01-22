class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxi=-1;
        int ans=0;
        while(r<nums.size()-1){
            for(int i=l;i<=r;i++){
                maxi=max(maxi,i+nums[i]);
            }
            ans++;
            l=r+1;
            r=maxi;
        }
        return ans;
        
    }
};