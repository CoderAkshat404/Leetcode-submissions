class Solution {
public:
    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }
        long long x=n-1;
        long long y=n+x;
        long long z=y-2;
        long long p=(z/2)+1;
        long long sum=p*p;
        cout<<sum<<endl;
        return (sum*2)+y;
        
    }
};