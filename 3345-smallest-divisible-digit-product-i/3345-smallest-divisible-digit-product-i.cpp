class Solution {
public:
    int solve(int n){
        int pro=1;
        while(n>0){
            pro=pro*(n%10);
            n=n/10;
        }
        return pro;

    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100100;i++){
            int pro=solve(i);
            if(pro%t==0) return i;
        }
        return n;
        
    }
};