class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int d=abs(nums[i]-nums[i+1]);
            maxi=max(maxi,d);
        }
        return maxi;
        
    }
};