class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        int x=1;
        while(x*x<=n){
            ans++;
            x++;
        }
        return ans;
        
    }
};