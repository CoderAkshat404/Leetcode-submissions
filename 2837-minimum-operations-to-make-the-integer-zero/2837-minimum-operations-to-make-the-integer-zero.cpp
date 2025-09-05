class Solution {
public:
    bool solve(long long n, long long k) {
        int x = 0;
        for (int i = 0; i < 64; i++) {
            int b = (n >> i) & 1;
            if (b == 1) {
                x++;
            }
        }
        return x <= k;
    }

    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1, n2 = num2;  

        if (n1 <= n2) {  
            return -1;  
        }

        for (int i = 1; i <= 100000; i++) {  
            n1 -= n2;
            if (n1 <= 0) break;
            if (solve(n1, i) && n1>=i) return i;
        }
        return -1;
    }
};
