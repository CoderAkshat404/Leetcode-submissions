vector<int> v;

class Solution {
public:
    vector<int> primes(int n) {
        vector<int> v(n + 1, 1);
        v[0] = v[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (v[i]) {
                for (int j = i * i; j <= n; j += i) {
                    v[j] = 0;
                }
            }
        }
        return v;
    }

    vector<int> closestPrimes(int left, int right) {
        v = primes(right);
        int num1 = -1;
        int num2 = -1;
        int mini = INT_MAX;
        vector<int> arr;

        for (int i = left; i <= right; i++) {
            if (v[i] == 1) {
                arr.push_back(i);
            }
        }

        // Check if there are at least two primes
        if (arr.size() < 2) {
            return {-1, -1};
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] < mini) {
                num1 = arr[i];
                num2 = arr[i + 1];
                mini = arr[i + 1] - arr[i];
            }
        }

        return {num1, num2};
    }
};
