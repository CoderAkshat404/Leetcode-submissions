class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(maxDoubles--){
            if(target==1){
                break;
            }
            if(target&1){
                ans++;
            }
            target=target/2;
            ans++;
        }
        return ans+target-1;
        
    }
};