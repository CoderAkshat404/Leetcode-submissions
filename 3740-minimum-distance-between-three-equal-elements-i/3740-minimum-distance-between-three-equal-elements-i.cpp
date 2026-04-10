class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int mini=1e9;
        for(auto i:m){
            vector<int> v=i.second;
            if(v.size()<=2){
                continue;
            }
            for(int j=1;j<v.size()-1;j++){
                int x=(v[j]-v[j-1])+(v[j+1]-v[j])+(v[j+1]-v[j-1]);
                mini=min(mini,x);

            }
        }
        if(mini==1e9){
            return -1;
        }
        return mini;
    }
};