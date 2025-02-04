class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int count=0;
            for(int j=0;j<points.size();j++){
                int x1=queries[i][0];
                int x2=points[j][0];
                int y1=queries[i][1];
                int y2=points[j][1];
                int r=queries[i][2];
                if((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))<=r*r){
                    count++;
                }
            }
        ans.push_back(count);
        }
    return ans;    
    }
};