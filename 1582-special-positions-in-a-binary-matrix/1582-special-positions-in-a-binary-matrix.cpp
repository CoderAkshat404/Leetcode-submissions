class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    bool flag=true;
                    for(int k=0;k<j;k++){
                        if(mat[i][k]==1){
                            flag=false;
                            break;
                        }
                    }
                    for(int k=j+1;k<m;k++){
                        if(mat[i][k]==1){
                            flag=false;
                            break;
                        }
                    }
                    for(int k=0;k<i;k++){
                        if(mat[k][j]==1){
                            flag=false;
                            break;
                        }
                    }
                    for(int k=i+1;k<n;k++){
                        if(mat[k][j]==1){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        ans++;
                    }


                }
            }
        }
        return ans;
        
    }
};