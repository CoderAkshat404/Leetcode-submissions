class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        long long x=(long long)n-1;
        if((x & (long long)n)==0){
            return true;
        }
        return false;
        
    }
};