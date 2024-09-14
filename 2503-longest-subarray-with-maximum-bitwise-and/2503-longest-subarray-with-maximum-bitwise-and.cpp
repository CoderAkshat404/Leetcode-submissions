class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.rbegin(),v.rend());
        int e=v[0];
        int count=1;
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==e && nums[i+1]==e){
                count++;
                maxi=max(maxi,count);
            }
            else{
                count=1;
            }
        }
        return maxi;

        
    }
};