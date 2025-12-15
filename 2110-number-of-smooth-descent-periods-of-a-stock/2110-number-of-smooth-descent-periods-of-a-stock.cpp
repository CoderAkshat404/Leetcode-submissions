class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        #define int long long
        int ans=0;
        int cnt=1;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]==-1){
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=1;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
        #undef int
        
    }
};