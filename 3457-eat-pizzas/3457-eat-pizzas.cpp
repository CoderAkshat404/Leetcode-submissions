class Solution {
public:
    long long maxWeight(vector<int>& arr) {
        #define int long long
        sort(arr.begin(),arr.end());
        int days=arr.size()/4;
        int odd=(days+1)/2;
        int even=days-odd;
        int ans=0;
        int j=arr.size()-1;
        while(odd--){
            ans+=arr[j];
            j--;

        }
        j--;
        while(even--){
            ans+=arr[j];
            j-=2;
        }
        return ans;
        #undef int
        
    }
};