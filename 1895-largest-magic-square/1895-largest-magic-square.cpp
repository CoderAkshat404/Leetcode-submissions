class Solution {
public:
    bool check(int r,int c,int sz,vector<vector<int>>& grid){
        set<int> s;
       
        for(int i=r;i<=r+sz;i++){
             int sum=0;
             for(int j=c;j<=c+sz;j++){
                sum+=grid[i][j];
             }
             s.insert(sum);
     
        }
        for(int j=c;j<=c+sz;j++){
             int sum=0;
            for(int i=r;i<=r+sz;i++){
                sum+=grid[i][j];

            }
              s.insert(sum);
        }
        int i=r;
        int j=c;
        int sum=0;
        while(i<=r+sz){
            sum+=grid[i][j];
            i++;
            j++;


        }
        s.insert(sum);
        i=r+sz;
        j=c;
        sum=0;
        while(i>=r){
            sum+=grid[i][j];
            i--;
            j++;

        }
        s.insert(sum);
        return s.size()==1;


    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<min(n,m);k++){
                    if(i+k<n && j+k<m){
                        if(check(i,j,k,grid)){
                            ans=max(ans,k+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};