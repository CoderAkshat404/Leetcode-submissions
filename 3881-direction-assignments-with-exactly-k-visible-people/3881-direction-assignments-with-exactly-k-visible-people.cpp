class Solution {
public:
    
    int mod=1e9+7;
    
    vector<int> fact;

    long long binExp(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long inv(long long x) {
        return binExp(x, mod - 2);
    }
    long long  nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long num = fact[n];
        long long den = (inv(fact[r]) * inv(fact[n - r])) % mod;
        return (num * den) % mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        fact.resize(n+1);
        long long pro=1;
        fact[0]=1;
        for(int i=1;i<=n;i++){
            pro=(pro*i)%mod;
            fact[i]=pro;
        }
        if(k==0){
            k=n-1;    
        }
        int ans=0;
        int left=pos;
        int right=n-pos-1;
        for(int i=0;i<=k;i++){
            if(i>pos) break;
            long long ways = (nCr(left, i) * nCr(right, k-i)) % mod;
            ans=(ans+ways)%mod;
        }
        
    
        return (ans*2)%mod;
        
    }
};