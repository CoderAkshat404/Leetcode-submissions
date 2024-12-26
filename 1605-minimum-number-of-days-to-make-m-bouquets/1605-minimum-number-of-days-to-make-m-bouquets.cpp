class Solution {
public:
    int check(int mid,vector<int>& bloomDay, int m, int k){
        int x=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                count++;
            }
            else{
                x+=count/k;
                count=0;
            }
        }
        x+=count/k;
        if(x>=m){
            return 1;
        }
        else{
            return 0;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(bloomDay[i],maxi);
        }
        int lo=1;
        int hi=maxi;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,bloomDay,m,k)==1){
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