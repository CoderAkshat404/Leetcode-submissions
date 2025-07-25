class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int sum = 0;
        int mini = 0;
        int maxi = 0;
        int maxs = -1e9;
        int mins = 1e9;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxs = max(maxs, sum - mini);  
            mins = min(mins, sum - maxi);  
            mini = min(mini, sum);       
            maxi = max(maxi, sum);         
        }
        if (sum == mins) return maxs;
        return max(maxs, sum - mins);
    
        
    }
};