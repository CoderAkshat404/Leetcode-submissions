class Solution {
public:
    int check(int mid,vector<int>& v, int m, int k){
        int cnt=0;
        int ans=0;
        for(auto i:v){
            if(i<=mid){
                cnt++;
                if(cnt==k){
                    ans++;
                    cnt=0;
                }
            }
            else{
                cnt=0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,v,m,k)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
};