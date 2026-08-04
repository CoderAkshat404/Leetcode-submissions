class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int oddc=0;
            int evenc=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    evenc++;
                }
                else{
                    oddc++;
                }
                if(oddc>0 && (evenc*b)<=(oddc*a)){
                ans++;
                }
            }
            
        }
        return  ans;
    }
};