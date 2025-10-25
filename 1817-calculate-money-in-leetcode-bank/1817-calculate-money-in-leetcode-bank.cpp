class Solution {
public:
    int totalMoney(int n) {
        int prev=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            prev++;
            
            ans+=prev;
            if(i%7==0){
                prev=i/7;
            }


        }
        return ans;
        
    }
};