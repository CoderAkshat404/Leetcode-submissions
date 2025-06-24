class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> m;
        vector<int> ans;
        for(int i=0;i<k;i++){
            m.insert(nums[i]);
        }
        ans.push_back(*m.rbegin());
        int i=0;
        int j=k-1;
        while(j+1<n){
            m.insert(nums[j+1]);
            m.erase(m.find(nums[i]));
             ans.push_back(*m.rbegin());
             i++;
             j++;

        }
        return ans;
        
    }
};