class Solution {
public:
    int arrangeCoins(int n) {
        long long  l=0;
        long long  r=INT_MAX;
        while(r-l>1){
            long long  m=r-(r-l)/2;
            if((m*(m+1))/2<=n){
                l=m;
            }
            else{
                r=m;
            }
        }
        return l;
        
    }
};