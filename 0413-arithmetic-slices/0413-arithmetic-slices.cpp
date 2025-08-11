class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return 0;
        }
        int prev=nums[1]-nums[0];
        int cnt=2;
        int ans=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==prev){
                cnt++;
            }
            else{
                if(cnt>2){
                    ans+=(cnt*(cnt+1))/2;
                    ans-=(2*cnt-1);
                }
                prev=nums[i]-nums[i-1];
                cnt=2;

            }
        }
         if(cnt>2){
            ans+=(cnt*(cnt+1))/2;
            ans-=(2*cnt-1);
        }
        return ans;
            


        
    }
};