class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> v=nums;
        int p=k;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==-1){
                nums[i]=1;
                nums[i+1]*=-1;
                p--;
                if(p==0){
                    break;
                }
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(v[i]==1){
                v[i]=-1;
                v[i+1]*=-1;
                k--;
                if(k==0){
                    break;
                }
            }
        }
        if((count(nums.begin(),nums.end(),-1)>0) && (count(v.begin(),v.end(),1)>0)) return false;
        return true;
        
    }
};