class Solution {
public:
    int mini=1e9;
    int ans=1e9;
    void solve(int i,vector<int>& t,int pick,int cost,int currsum,int target){
        if(i>=t.size()){
            int totalcost=cost+currsum;
            if(abs(totalcost-target)<mini){
                ans=totalcost;
                mini=abs(totalcost-target);
            }
            else if(abs(totalcost-target)==mini){
                ans=min(ans,totalcost);
            }
            return ;

        }
        if(pick>0){
        solve(i,t,pick-1,cost,currsum+t[i],target);
        }
        solve(i+1,t,2,cost,currsum,target);


    }
    int closestCost(vector<int>& b, vector<int>& t, int target) {
        for(int i=0;i<b.size();i++){
            solve(0,t,2,b[i],0,target);
        }
        return ans;

        
    }
};