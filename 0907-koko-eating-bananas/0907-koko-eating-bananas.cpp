class Solution {
public:
    int check(int m,vector<int>& piles, int h){
        int l=0;
        for(int i=0;i<piles.size();i++){
            l+=ceil((double)piles[i]/m);
        }
        if(l<=h){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MAX;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int lo=1;
        int hi=maxi;
        int ans=-1;
        while(lo<=hi){
            int m=hi-(hi-lo)/2;
            if(check(m,piles,h)==1){
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