class Solution {
public:
    int check(int m,vector<int>& quantities,int n){
        int a=0;
        for(int i=0;i<quantities.size();i++){
            a+=(quantities[i]+m-1)/m;
        }
        if(a<=n){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi=INT_MIN;
        for(int i=0;i<quantities.size();i++){
            maxi=max(maxi,quantities[i]);
        }
        int lo=1;
        int hi=maxi;
        int ans=-1;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,quantities,n)==1){
                hi=m-1;
                ans=m;
            }
            else{
                lo=m+1;
            }
        }
        return ans;
        
    }
};