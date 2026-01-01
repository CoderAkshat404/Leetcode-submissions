class Solution {
public:
    bool check(set<int> & s,int r,int c,vector<vector<int>>& grid){
        set<int> x;
        for(int i=r;i<=r+2;i++){
            for(int j=c;j<=c+2;j++){
                if((grid[i][j]<1 || grid[i][j]>9) || x.find(grid[i][j])!=x.end()){
                    
                    return false;
                }
                x.insert(grid[i][j]);
            }
        }
        
        for(int i=r;i<=r+2;i++){
            int sum=0;
            for(int j=c;j<=c+2;j++){
                sum+=grid[i][j];
            }
            s.insert(sum);
        }
        for(int i=c;i<=c+2;i++){
            int sum=0;
            for(int j=r;j<=r+2;j++){
                sum+=grid[j][i];
            }
            s.insert(sum);
        }
        int sum=0;
        int i=r;
        int j=c;
        while(i<r+3 && j<c+3){
            sum+=grid[i][j];
            i++;
            j++;
        }
        s.insert(sum);
        i=r;
        j=c+2;
        sum=0;
        while(i<r+3 && j>=c){
            sum+=grid[i][j];
            i++;
            j--;
        }
         s.insert(sum);
         return s.size()==1;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+2<n && j+2<m){
                    set<int> s;
                    if(check(s,i,j,grid)){
                        ans++;
                    }   
                }
            }
        }
        return ans;
        
    }
};