class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int x=count(nums.begin(),nums.end(),nums[0]);
        int y=count(nums.begin(),nums.end(),nums.back());
        if(k==1){
            unordered_map<int,int> m;
            for(auto i:nums){
                m[i]++;
            }
            int maxi=-1;
            for(auto i:m){
                if(i.second==1){
                    maxi=max(maxi,i.first);
                }
            }
            return maxi;
        }
        if(k==nums.size()){
            int maxi=-1;
            for(auto i:nums){
                maxi=max(maxi,i);
            }
            return maxi;


        }
        if(x>1 && y>1){
            return -1;
        }
        else{
            if(y>1){
                return nums[0];
            }
            if(x>1){
                return nums.back();

            }
            return max(nums[0],nums.back());
        }
        
    }
};