class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxpos=-1;
        int maxi=-1e9;
        int mini=1e9;
        int minpos=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxpos=i;
            }
            if(mini>nums[i]){
                mini=nums[i];
                minpos=i;
            }
        }
     
        int x=max(minpos,maxpos)+1;
        int y=nums.size()-min(minpos,maxpos);
        int z=min(minpos,maxpos)+1+nums.size()-max(minpos,maxpos);
       
        return min(x,min(y,z));
        
    }
};