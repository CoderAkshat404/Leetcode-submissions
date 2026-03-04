class Solution {
public:
    int check(int mid,int m,int n, int k){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(n,mid/i);
        }
        return cnt>=k;

    }
    int findKthNumber(int m, int n, int k) {
        int lo=1;
        int hi=1e9;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,m,n,k)){
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