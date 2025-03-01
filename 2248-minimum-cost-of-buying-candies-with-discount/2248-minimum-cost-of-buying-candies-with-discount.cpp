class Solution {
public:
    int minimumCost(vector<int>& cost) {
        long long int ans=0;
        sort(cost.rbegin(),cost.rend());
        int n =cost.size();
        for(int i=0;i<n;i++){
            if((i+1)%3==0){
                continue;
            }
            else{
                ans+=cost[i];
            }
        }
        return ans;
        
    }
};