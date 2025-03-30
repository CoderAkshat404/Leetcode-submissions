class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int currmini=INT_MAX;
        for(int i=0;i<cost.size();i++){
            if(cost[i]<currmini){
                currmini=cost[i];
            }
            ans.push_back(currmini);
        }
        return ans;
        
    }
};