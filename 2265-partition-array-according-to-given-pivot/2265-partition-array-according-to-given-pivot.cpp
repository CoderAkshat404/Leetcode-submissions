class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans;
    vector<int>left;
    vector<int>right;
    vector<int>piv;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==pivot){
            piv.push_back(nums[i]);
        }
        if(nums[i]<pivot){
            left.push_back(nums[i]);
        }
        if(nums[i]>pivot){
            right.push_back(nums[i]);
        }
    }
    for(int i=0;i<left.size();i++){
        ans.push_back(left[i]);    
    }
    for(int i=0;i<piv.size();i++){
        ans.push_back(piv[i]);    
    }
    for(int i=0;i<right.size();i++){
        ans.push_back(right[i]);    
    }
return ans;
}
};