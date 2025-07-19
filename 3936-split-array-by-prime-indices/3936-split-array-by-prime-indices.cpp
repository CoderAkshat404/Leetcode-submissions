class Solution {
public:
    long long splitArray(vector<int>& nums) {
        #define int long long
        int n=nums.size();
        vector<int> spf(n+1);
        for(int i=2;i<n;i++){
            spf[i]=i;
        }
        for(int i=2;i<n;i++){
            if(spf[i]==i){
                for(int j=2*i;j<n;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        int s1=0;
        int s2=0;
        for(int i=0;i<n;i++){
            if(i==0 || i==1){
                s1+=nums[i];
            }
            else if(spf[i]==i){
                s2+=nums[i];
            }
            else{
                s1+=nums[i];
                
            }
        }
        
        return abs(s1-s2);
        #undef int
        
    }
};