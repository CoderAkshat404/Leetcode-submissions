class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int ans=0;
        while(i<n && nums[i]!=0){
            i++;
        }
        if(i==n){
            return 0;
        }
        ans=1;
        int prev=0;
        while(i<n){
            if(prev==0){
                while(i<n && nums[i]!=1){
                    i++;
                }
                if(i!=n){
                    prev=1;
                    ans++;
                }
            }
            else{
                while(i<n && nums[i]!=0){
                    i++;
                }
                if(i!=n){
                    prev=0;
                    ans++;
                }

            }
        }
        return ans;
        
    }
};