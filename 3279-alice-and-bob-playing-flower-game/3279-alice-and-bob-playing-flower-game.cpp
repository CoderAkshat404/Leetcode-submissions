class Solution {
public:
    long long flowerGame(int n, int m) {
        #define int long long
        int evenc1=n/2;
        int evenc2=m/2;
        int oddc1=n/2;
        int oddc2=m/2;
        if(n&1){
            oddc1++;
        }
        if(m&1){
            oddc2++;
        }
        int x=oddc1*evenc2;
        int y=oddc2*evenc1;
        return x+y;
        #undef int
        
    }
};