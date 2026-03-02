class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        map<int,int> m;
        for(int i=0;i<grid.size();i++){
            int cnt=0;
            for(int j=grid[i].size()-1;j>=0;j--){
                if(grid[i][j]==0){
                    cnt++;
                }
                else{
                    break;
                }
            }
            m[i]=cnt;
            
        }
        int ans=0;
        vector<int> v(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            int req=grid.size()-i-1;
            int posi=-1;
            for(int j=i;j<grid.size();j++){
                if(m[j]>=req){
                    posi=j;
                    break;

                }
            }
            if(posi==-1){
                return -1;
            }
            int val = m[posi];  
            for(int j=posi;j>i;j--){
               int prev=m[j-1];
               m[j]=prev;
            }
            m[i] = val;
            ans+=(posi-i);
           


        }
        return ans;
        
    }
};