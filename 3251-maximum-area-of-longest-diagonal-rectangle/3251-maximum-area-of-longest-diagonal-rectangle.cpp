class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        int maxi=0;
        for(int i=0;i<dimensions.size();i++){
            int x=dimensions[i][0];
            int y=dimensions[i][1];
            int d=(x*x)+(y*y);
            if(d>maxi){
                maxi=d;
                ans=x*y;
            }
            else if(d==maxi){
                ans=max(ans,x*y);
            }
        }
        return ans;
        
    }
};