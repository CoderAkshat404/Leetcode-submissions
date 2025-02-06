class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int x=nums[i]*nums[j];
                m[x]++;

            }
        }
        int ans=0;
        for(auto i:m){
            int y=i.second-1;
            ans+=(((y)*(y+1))/2)*8;
        }
        return ans;
        
    }
};