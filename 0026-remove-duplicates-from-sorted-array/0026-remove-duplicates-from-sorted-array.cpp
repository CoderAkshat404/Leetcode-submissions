class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int idx=0;
        int cnt=0;
        while(j<nums.size()){
            int curr=nums[j];
            while(j<nums.size() && nums[j]==curr){
                j++;
            }
            nums[i]=curr;
           
            cnt++;
            i++;
        }
        return cnt;
        
    }
};