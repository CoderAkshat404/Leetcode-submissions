class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> s;
        for(int i=0;i<nums.size();i++){
            if(!s.empty() && s.top()==nums[i]){
                long long curr=s.top()+nums[i];
                s.pop();
                while(!s.empty() && curr==s.top()){
                    curr=(long long)2*s.top();
                    s.pop();
                }
                s.push(curr);
            }
            else{
            s.push(nums[i]);}
        }
        vector<long long> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};