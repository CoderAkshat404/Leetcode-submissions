class Solution {
public:
    vector<int> h;
    int maxi=0;
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        h.resize(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    h[j]=0;
                }
                else{
                    h[j]=1+h[j];
                }
            }
            vector<int> v=h;
            sort(v.begin(),v.end());
            for(int j=0;j<m;j++){
                maxi=max(maxi,(m-j)*v[j]);

            }
            
        }
        return maxi;

        
        
    }
};