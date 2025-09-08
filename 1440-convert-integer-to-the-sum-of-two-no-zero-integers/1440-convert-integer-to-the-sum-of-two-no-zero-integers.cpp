class Solution {
public:
    bool solve(int n){
        bool flag=false;
        while(n!=0){
            int x=n%10;
            if(x==0){
                return false;
            }
            n=n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n-1;i++){
            int x=i;
            int y=n-x;
            if(solve(x) && solve(y)){
                return {x,y};
            }
        }
        return {};
    }
};