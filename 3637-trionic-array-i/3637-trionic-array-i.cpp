class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<=n-3;i++){
            bool f1=true;
            for(int k=1;k<=i;k++){
                if(nums[k]<=nums[k-1]){
                    f1=false;
                    break;
               }
            }
            for(int j=i+1;j<n-1;j++){
                bool f2=true;
                for(int k=i+1;k<=j;k++){
                    if(nums[k]>=nums[k-1]){
                        f2=false;
                        break;
                    }
                }
                bool f3=true;
                for(int k=j+1;k<n;k++){
                    if(nums[k]<=nums[k-1]){
                        f3=false;
                        break;
                    }    
                }
                if(f1 && f2 && f3) return true;
            }
        }
      return false;  
    }
};