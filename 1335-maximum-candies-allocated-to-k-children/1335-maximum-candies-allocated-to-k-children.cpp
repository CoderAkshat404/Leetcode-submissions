class Solution {
public:
    int check(long long m, long long k,vector<int>& candies){
        long long  s=0;
        for(int i=0;i<candies.size();i++){
            s+=(candies[i])/m;
        }
        if(s>=k) return  true;
        else return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long  maxi=INT_MIN;
        for(auto i:candies){
            maxi=max((long long)i,maxi);
        }
        long long  lo=1;
        long long  hi=maxi;
        long long  ans=0;
        while(lo<=hi){
            long long  m=lo+(hi-lo)/2;
            if(check(m,k,candies)){
                ans=m;
                lo=m+1;

            }
            else{
                hi=m-1;
            }
        }
        return ans;
        
    }
};