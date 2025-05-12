class Solution {
public:
    long long fastExpIter(long long b, long long e, long long m) { long long r = 1; for (b %= m; e; e /= 2, b = b * b % m) if (e % 2) r = r * b % m; return r; }
    int countGoodNumbers(long long n) {
        long long ans=1;
        long long odd=n/2;
        long long even=n-odd;
        cout<<even<<" "<<odd<<endl;
        ans=(ans*fastExpIter(4,odd,1000000007)*fastExpIter(5,even,1000000007))%1000000007;
  
        return ans;


        
    }
};