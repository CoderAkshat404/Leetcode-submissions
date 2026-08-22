class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int digits=0;
        int digitp=1;
        while(x!=0){
            int d=x%10;
            x=x/10;
            digits+=d;
            digitp*=d;
        }
        return (n%(digits+digitp)==0);
        
    }
};