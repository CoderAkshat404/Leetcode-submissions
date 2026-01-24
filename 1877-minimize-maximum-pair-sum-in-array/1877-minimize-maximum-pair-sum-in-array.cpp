class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int maxi=-1;
        while(i<j){
            int s=nums[i]+nums[j];
            maxi=max(maxi,s);
            i++;
            j--;

        }
        return maxi;
    }
};