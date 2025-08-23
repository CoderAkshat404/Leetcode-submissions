class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n,0);
        set<pair<int,int>> s;
        for(int i=0;i<roads.size();i++){
            indeg[roads[i][0]]++;
            indeg[roads[i][1]]++;
            int x=roads[i][0];
            int y=roads[i][1];
            if(x>y){
                swap(x,y);
            }
            s.insert({x,y});
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int val=0;
                if(s.find({i,j})!=s.end()){
                    val=1;
                }
                maxi=max(maxi,indeg[i]+indeg[j]-val);
            }
        }
        return maxi;
    }
};