class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto i:m){
            v.push_back(i.first);
        }
        sort(v.rbegin(),v.rend());
        if(v[0]<0){
                return v[0];
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<0){
            break;}
            ans+=v[i];

        }
        return ans;
        
    }
};