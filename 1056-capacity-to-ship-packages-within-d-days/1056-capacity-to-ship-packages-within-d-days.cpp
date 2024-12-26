class Solution {
public:
    int check(int m,vector<int>& weights, int days){
        int s=0;
        int x=0;
        for(int i=0;i<weights.size();i++){
            s+=weights[i];
            if(s>m){
                s=0;
                s+=weights[i];
                x++;
            }
        }
        if(s>0){
            x++;
        }
        if(x<=days){
            return 1;
        }
        else{
            return 0;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            s+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int lo=maxi;
        int hi=s;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,weights,days)==1){
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