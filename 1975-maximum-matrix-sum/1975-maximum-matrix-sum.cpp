class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        #define int long long
        int ans=0;
        int cnt=0;
        int mini=1e9;
        int sum=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    cnt++;
                }
                mini=min(mini,(long long)abs(matrix[i][j]));
            }
        }
       
        if(cnt&1){
            sum=sum-2*mini;
        }
        return sum;
        #undef int
        
    }
};