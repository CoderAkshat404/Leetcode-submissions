class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> primes(100100,1);
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i<100100;i++){
            if(primes[i]==1){
                for(int j=2*i;j<100100;j+=i){
                    primes[j]=0;
                }
            }
        }
        vector<int> p;
        for(int i=2;i<100100;i++){ 
            if(primes[i]==1){
                p.push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                int idx=lower_bound(p.begin(),p.end(),nums[i])-p.begin();
                ans+=p[idx]-nums[i];
            }
            else{
                if(primes[nums[i]]==1){
                if(nums[i]==2){
                    ans+=2;
                }
                else{
                    ans++;
                }
                }
            }
            
        }
        return ans;
        
        
    }
};