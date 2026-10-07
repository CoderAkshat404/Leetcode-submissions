class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        for(auto i:nums){
            m[i]++;
        }
        bool flag=true;
        while(flag){
            flag=false;
            for(auto i:m){
                if(i.second>0){
                    flag=true;
                    ans.push_back(i.first);
                    m[i.first]--;
                }
            }
        }
        return ans;
        
    }
};