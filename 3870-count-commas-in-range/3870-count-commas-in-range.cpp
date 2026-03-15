class Solution {
public:
    int calsize(int n){
        int x=0;
        while(n!=0){
            x++;
            n=n/10;
        }
        return x;
    }
    int countCommas(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=calsize(i)/4;
        }
        return ans;
        
    }
};