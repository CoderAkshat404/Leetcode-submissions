class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> prefmin;
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            prefmin.push_back(mini);
        }
        mini=1e9;
        vector<int> suffmin;
        for(int i=nums.size()-1;i>=0;i--){
            mini=min(mini,nums[i]);
            suffmin.push_back(mini);
        }
        reverse(suffmin.begin(),suffmin.end());
        int minsum=1e9;
        for(int i=1;i<nums.size()-1;i++){
            if(prefmin[i-1]<nums[i] && suffmin[i+1]<nums[i]){
                minsum=min(minsum,nums[i]+prefmin[i-1]+suffmin[i+1]);
            }
        }
        if(minsum==1e9) return -1;
        return minsum;

        
        
    }
};