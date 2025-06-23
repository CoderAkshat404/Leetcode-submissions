class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        int x=nums.size();
        stack<int> s;
        for(int i=x-1;i>=0;i--){
            if(s.empty()){
                s.push(nums[i]);
                if(i<n){
                    ans[i]=-1;
                }
            }
            else{
                while(!s.empty() && s.top()<=nums[i]){
                    s.pop();
                }
                if(!s.empty() && i<n){
                    ans[i]=s.top();
                }
                else if(i<n){
                    ans[i]=-1;
                }
                s.push(nums[i]);
            }
        }
        return ans;
    }
};