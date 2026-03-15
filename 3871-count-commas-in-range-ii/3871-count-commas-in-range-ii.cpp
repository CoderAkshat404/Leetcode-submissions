class Solution {
public:
    int calsize(int n){
        int x=0;
        while(n!=0){
            x++;
            n=n/10;
        }
        return x;
    }
    long long countCommas(long long n) {
        long long ans=0;
        long long start=1000;
        int commas=1;
        while(start<=n){
            int x=calsize(start);
            long long ul=(start*1000*1LL)-1;
            ans += (min(ul,n) - start + 1) *commas;
            start=start*1000*1LL;
            commas++;
        }
        return ans;
        
    }
};