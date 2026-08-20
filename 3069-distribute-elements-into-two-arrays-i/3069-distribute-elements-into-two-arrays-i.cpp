class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(v1.back()>v2.back()){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0;i<v1.size();i++){
            nums.push_back(v1[i]);

        }
        for(int i=0;i<v2.size();i++){
            nums.push_back(v2[i]);

        }
        return nums;
        
    }
};