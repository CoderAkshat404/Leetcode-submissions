class Solution {
public:
    int check(int k,vector<int>& piles, int h){
        long long sum=0;
        for(auto i:piles){
            sum+=(i+k-1)/k;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=1e9;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,piles,h)){
                ans=mid;
                hi=mid-1;

            }
            else{
                lo=mid+1;
            }
        }
        return ans;

        
        
    }
};