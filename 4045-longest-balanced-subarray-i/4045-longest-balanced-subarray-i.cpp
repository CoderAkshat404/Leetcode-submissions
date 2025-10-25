class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int> o;
            unordered_set<int> e;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    e.insert(nums[j]);
                }
                else{
                    o.insert(nums[j]);
                }
                if(o.size()==e.size()){
            ans=max(ans,j-i+1);}

            }
        }
     return ans;   
    }
};