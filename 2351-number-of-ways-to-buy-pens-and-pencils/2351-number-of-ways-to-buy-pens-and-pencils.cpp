class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        #define int long long
        int ans=0;
        for(int i=0;i<=(total/cost1);i++){
            int x=(total-(cost1*i));
            ans+=(x/cost2)+1;
        }
        return ans;
        #undef int
        
    }
};