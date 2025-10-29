class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(int i=0;i<circles.size();i++){
            int x1=circles[i][0];
            int y1=circles[i][1];
            int r=circles[i][2];
            for(int j=x1-r;j<=x1+r;j++){
                for(int k=y1-r;k<=y1+r;k++){
                    if((x1-j)*(x1-j)+(y1-k)*(y1-k)<=r*r){
                        s.insert({j,k});
                    }
                }
            }
        }
        return s.size();
        
    }
};