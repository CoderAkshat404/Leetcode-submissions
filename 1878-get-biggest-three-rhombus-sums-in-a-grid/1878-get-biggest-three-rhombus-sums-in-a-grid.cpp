class Solution {
public:
int n,m;
    int calcsum(int row,int col,vector<vector<int>>& grid,int size){
        int sum=0;
        int i=row;
        int j=col;
        for(int k=0;k<size;k++){
             if(i>=n || j>=m || i<0 || j<0) return -1;
            sum+=grid[i][j];
            i--;
            j--;
        }
        i++;
        j++;
        sum-=grid[i][j];
        for(int k=0;k<size;k++){
             if(i>=n || j>=m || i<0 || j<0) return -1;
            sum+=grid[i][j];
            i--;
            j++;

        }
        i++;
        j--;
        sum-=grid[i][j];
        for(int k=0;k<size;k++){
             if(i>=n || j>=m || i<0 || j<0) return -1;
            sum+=grid[i][j];
            i++;
            j++;
        }
        i--;
        j--;
        sum-=grid[i][j];
        for(int k=0;k<size;k++){
             if(i>=n || j>=m || i<0 || j<0) return -1;
            sum+=grid[i][j];
            i++;
            j--;
        }
        i--;
        j++;
        sum-=grid[i][j];
        return sum;



    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        n=grid.size();
         m=grid[0].size();
        set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s.insert(grid[i][j]); 
                for(int sz=1;sz<=n;sz++){
                int sum=calcsum(i,j,grid,sz);
                if(sum>0){
                s.insert(sum);}}


            }
        }
        vector<int> ans;
        for(int i=0;i<3 && !s.empty();i++){
            ans.push_back(*s.rbegin());
            s.erase(*s.rbegin());
        }
        
        return ans;
        
    }
};