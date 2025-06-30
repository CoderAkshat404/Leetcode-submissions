class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        int prev=-1;
        for(auto i:m){
            if(i.first-prev==1){
                ans=max(ans,i.second+m[prev]);
            }
            prev=i.first;
        }
        return ans;
        
    }
};