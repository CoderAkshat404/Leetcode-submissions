class Solution {
public:
    long long mod=1e9+7;
    long long binpow(long long a,long long b){
        if(b==0) return 1;
        if(b&1){
            return (a*binpow(a,b-1))%mod;
        }
        else{
            long long temp=binpow(a,b/2);
            return (temp*temp)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans=binpow(5,even);
        ans=(ans*binpow(4,odd))%mod;
        return ans;
        
    }
};