class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x=n*n;
        int y=n*n + n;
        return __gcd(x,y);
        
    }
};