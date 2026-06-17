class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        #define int long long
        int ans=0;
        int diff=0;
        if(arr.size()==1) return abs(arr[0]-brr[0]);
        for(int i=0;i<arr.size();i++){
           diff+=abs(arr[i]-brr[i]);
        }
        
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i=0;i<arr.size();i++){
            ans+=abs(arr[i]-brr[i]);
        }
        return min(ans+k,diff);
        #undef int
        
    }
};