class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i]-k,nums[i]+k});
        }
        sort(v.begin(),v.end());
        int smallest=INT_MIN;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first>smallest){
                ans++;
                smallest=v[i].first;
            }
            else if(smallest>=v[i].first && smallest<v[i].second){
                ans++;
                smallest++;
            }
        }
        return ans;
        
    }
};