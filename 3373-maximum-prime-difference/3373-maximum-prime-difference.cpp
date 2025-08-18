class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> spf(101);
        for(int i=0;i<=100;i++){
            spf[i]=i;
        }
        for(int i=2;i<=100;i++){
            if(spf[i]==i){
                for(int j=2*i;j<=100;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }

                }
            }
        }
        int findx=-1;
        int lindx=-1;
        for(int i=0;i<n;i++){
            if(spf[nums[i]]==nums[i] && nums[i]!=0 && nums[i]!=1){
                if(findx==-1){
                    findx=i;
                }
                lindx=i;
            }

        }
        return lindx-findx;
        
    }
};