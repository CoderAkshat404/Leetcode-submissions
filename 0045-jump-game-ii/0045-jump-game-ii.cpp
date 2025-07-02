class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n-1){
            int maxi=0;
            int maxj=0;
            for(int j=i+1;j<=i+nums[i];j++){
                if(j<n-1){
                    if(j+nums[j]>maxi){
                        maxi=j+nums[j];
                        maxj=j;
                    }
                }
                else{
                    return ans+1;
                }
                
            }
            i=maxj;
            ans++;
        }
        return ans;
        
    }
};