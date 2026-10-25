class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> corrupted;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK || nums[i]<minK){
                corrupted.push_back(i);
            }
        }
        long long ans=0;
        if(corrupted.empty()){
            int n=nums.size();
            return (1LL*(n)*(n+1)/2);
        }
        else{
            for(int i=0;i<corrupted.size()-1;i++){
                int x=(corrupted[i+1]-1)-(corrupted[i]+1)+1;
                ans+=(1LL*(x)*(x+1)/2);
            }
            int x=(corrupted[0]-1)-(0)+1;
            ans+=(1LL*(x)*(x+1)/2);
            int n=nums.size();
            x=(n-1)-(corrupted.back()+1)+1;
            ans+=(1LL*(x)*(x+1)/2);
        }
        return ans;
        
    }
};