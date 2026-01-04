class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l=0;
        int r=-1;
        int ans=1e9;
        int n=nums.size();
        int sum=0;
        map<int,int> m;
        while(l<n){
            while(r+1<n && sum<k){
                r++;
                if(m[nums[r]]==0){
                    sum+=nums[r];
                }
                m[nums[r]]++;
            }
            if(sum>=k){
                ans=min(ans,r-l+1);
            }
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                m[nums[l]]--;
                if(m[nums[l]]==0){
                    sum-=nums[l];
                }
                l++;
            }
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};