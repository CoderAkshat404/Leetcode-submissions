class Solution {
public:
    int check(int m,vector<int>& price, int k){
        int prev=price[0];
        int x=1;
        for(int i=0;i<price.size();i++){
            if(price[i]-prev>=m){
                x++;
                prev=price[i];
            }
        }
        if(x>=k){
            return 1;
        }
        else{
            return 0;
        }
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int lo=0;
        int hi=price.back()-price[0];
        int ans=0;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,price,k)==1){
                lo=m+1;
                ans=m;
            }
            else{
                hi=m-1;
            }
        }
        return ans;
        
    }
};