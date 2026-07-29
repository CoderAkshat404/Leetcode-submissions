class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        int pre=1;
        int suff=1;
        int ans=-1e9;
        for (int i = 0; i < n; i++) {
            pre *= arr[i];
            suff *= arr[n - i - 1];
            ans = max(ans, max(pre, suff));
             if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
        }
        return ans;
        
    }
};