class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans=0;
        map<int,int> maxi;
        map<int,int> mini;
        for(int i=0;i<nums.size();i++){
            if(mini.find(nums[i])==mini.end()){
                mini[nums[i]]=i;
            }
            maxi[nums[i]]=i;    
        }
        for(auto i:mini){
            int lstindx=maxi[i.first];
            bool flag=true;
            for(int j=i.second;j<=lstindx;j++){
                if(nums[j]!=i.first) flag=false;     
            }
            if(flag) ans++;
        }
        return ans;
    }
};