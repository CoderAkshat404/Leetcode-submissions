class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum1=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            sum1+=nums[i];
            int sum2=0;
            for(int j=i+1;j<nums.size();j++){
                sum2+=nums[j];
            }
            if(abs(sum1-sum2)%2==0){
                ans++;

            }
        }
        return ans;
        
    }
};