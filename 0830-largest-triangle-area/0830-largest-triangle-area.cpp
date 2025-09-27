class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi=INT_MIN;
        for(int i=0;i<points.size()-2;i++){
            for(int j=i+1;j<points.size()-1;j++){
                for(int k=j+1;k<points.size();k++){
                    int x1=points[i][0];
                    int x2=points[j][0];
                    int x3=points[k][0];
                    int y1=points[i][1];
                    int y2=points[j][1];
                    int y3=points[k][1];
                    // cout<<x1<<" "<<x2<<" "<<x3<<" "<<y1<<" "<<y2<<" "<<y3<<endl;
                    // double x=abs(((x1*(y2-y3))+(x2*(y3-y2))+(x3*(y1-y2))));
                    double x = abs((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2)));

                    
                    maxi=max(maxi,x/(double)2);
                }
            }
        }
        return maxi;
        
    }
};