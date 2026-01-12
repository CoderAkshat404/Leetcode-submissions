class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++){
            int hori=abs(points[i][0]-points[i-1][0]);
            int vert=abs(points[i][1]-points[i-1][1]);
            if(vert==hori){
                ans+=vert;
            }
            else{
                ans+=abs(vert-hori);
                ans+=min(vert,hori);
            }
        }
        return ans;
        
    }
};