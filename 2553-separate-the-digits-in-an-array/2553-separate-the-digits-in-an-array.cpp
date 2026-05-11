class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            int ele=i;
            vector<int> v;
            while(ele>0){
                v.push_back(ele%10);
                ele=ele/10;
            }
            reverse(v.begin(),v.end());
            for(auto j:v){
                ans.push_back(j);
            }
        }
        return ans;
        
    }
};