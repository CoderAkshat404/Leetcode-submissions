class Solution {
public:
    long long countCommas(long long n) {
        #define int long long
        if(n<1000) return 0;

        int ans=0;

        if(n>=1000){
            ans+=min(999999*1LL,n)-1000+1;
        }

        if(n>=1000000){
            ans+=(min(999999999*1LL,n)-1000000+1)*2LL;
        }

        if(n>=1000000000){
            ans+=(min(999999999999*1LL,n)-1000000000+1)*3LL;
        }

        if(n>=1000000000000){
            ans+=(min(999999999999999*1LL,n)-1000000000000+1)*4LL;
        }

      
        if(n>=1000000000000000LL){
            ans+=(n-1000000000000000LL+1)*5LL;
        }

        return ans;
        #undef int
    }
};