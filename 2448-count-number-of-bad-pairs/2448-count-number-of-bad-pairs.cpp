class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int d=nums[i]-(i+1);
            m[d]++;
            
        }
        long long  ans=0;
        for(auto i:m){
            long long int x=i.second;
            long long int y=x-1;
            ans+=((y)*(y+1))/2;
        }
        long long  z=nums.size()-1;
        long long total=(z*(z+1))/2;
        return total-ans;
        
        
    }
};