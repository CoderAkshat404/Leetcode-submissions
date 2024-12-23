class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0;
        int hi=arr.size();
        int ans=-1;
        while(lo<=hi){
            int m=(lo+hi)/2;
            if(m==arr.size()-1 || arr[m]>arr[m+1]){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};