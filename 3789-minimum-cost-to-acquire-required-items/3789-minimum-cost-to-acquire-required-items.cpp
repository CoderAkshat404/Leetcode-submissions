class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        #define int long long
        int ans=0;
        if(cost1>costBoth){
            ans+=(long long)need1*costBoth;
            need2-=need1;
            if(need2>0){
                if(cost2>costBoth){
                    ans+=(long long)need2*costBoth;

                }
                else{
                    ans+=(long long)need2*cost2;
                }
            }
            return ans;
        }
        else if(cost2>costBoth){
            ans+=(long long)need2*costBoth;
            need1-=need2;
             if(need1>0){
                if(cost1>costBoth){
                    ans+=(long long)need1*costBoth;

                }
                else{
                    ans+=(long long)need1*cost1;
                }
            }
            return ans;

        }
        else{
            int x=(long long)need1*cost1;
            int y=(long long)need2*cost2;
            int a=min(need1,need2);
            int z=(long long)min(need1,need2)*costBoth;
            need1=need1-a;
            need2=need2-a;
            if(need1>0){
                z+=(long long)need1*cost1;
            }
            if(need2>0){
                z+=(long long)need2*cost2;
            }
            return min(x+y,z);

        }
        #undef int
        
    }
};