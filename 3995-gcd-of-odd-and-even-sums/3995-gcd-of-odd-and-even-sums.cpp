class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int total=(2*n*(2*n+1))/2;
        int sumodd=n*n;
        int sumeven=total-sumodd;
        return __gcd(sumodd,sumeven);
        
    }
};