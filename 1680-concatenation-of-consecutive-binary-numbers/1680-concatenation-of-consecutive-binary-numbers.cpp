class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod=1e9+7;
        long long ans=0;
        long long p=1;
        for(int i=n;i>=1;i--){
            int x=i;
            while(x){
                if(x&1){
                    ans=(ans+p)%mod;
                }
                p=(p*2)%mod;
                x>>=1;
            }
        }
        return ans;
    }
};