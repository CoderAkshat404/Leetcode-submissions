class Solution {
public:
    map<int,int> m;
    int solve(long long n){
        if(n==1){
            return 0;
        }
        if(m.find(n)!=m.end()) return m[n];
        if(n&1){
            return m[n]=1+min(solve(n+1),solve(n-1));
        }
        return m[n]=1+solve(n/2);
    }
    int integerReplacement(int n) {
        return solve(n);
        
    }
};