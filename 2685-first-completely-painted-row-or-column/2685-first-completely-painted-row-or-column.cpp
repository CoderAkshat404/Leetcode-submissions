class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i;
        }
        int rmin=INT_MAX;
        for(int i=0;i<mat.size();i++){
            int maxi=INT_MIN;
            for(int j=0;j<mat[0].size();j++){
                maxi=max(maxi,m[mat[i][j]]);
            }
            rmin=min(rmin,maxi);
        }
        int cmin=INT_MAX;
         for(int j=0;j<mat[0].size();j++){
            int maxi=INT_MIN;
            for(int i=0;i<mat.size();i++){
                maxi=max(maxi,m[mat[i][j]]);

            }
            cmin=min(cmin,maxi);

         }
         return min(cmin,rmin);

        
    }
};