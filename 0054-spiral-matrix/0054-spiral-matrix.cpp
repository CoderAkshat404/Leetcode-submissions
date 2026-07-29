class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        int top=0;
        int left=0;
        int bottom=n-1;
        int right=m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(nums[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(nums[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(nums[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(nums[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};