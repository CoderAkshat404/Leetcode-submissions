class Solution {
public:
    vector<int> solve(string s){
        int n=s.length();
        vector<int> kmp(n+1);
        kmp[0]=-1;
        int i=0;
        int j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j=kmp[j];
            }
            i++;
            j++;
            kmp[i]=j;
        }
        return kmp;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n=grid.size();
        int m=grid[0].size();
        string s="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
        }
        int len=pattern.size();
        unordered_map<int,int> hori;
        vector<int> indices=solve(pattern+"$"+s);
        reverse(indices.begin(),indices.end());
        for(int i=0;i<=pattern.length()+1;i++){
            indices.pop_back();
        }
        reverse(indices.begin(),indices.end());
        // for(auto i:indices){
        //     cout<<i<<" ";
        // }
       
        // cout<<endl;
        // cout<<indices.size()<<endl;
        int st=-1;
        int end=-1;
        for(int i=indices.size()-1;i>=0;i--){
            if(indices[i]==len){
                cout<<i<<endl;
                st=i;
                end=st-len+1;
            }
            if(i<=st && i>=end){
                hori[i]=true;
            }
        }
        s="";
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                s+=grid[i][j];
            }
        }
        unordered_map<int,int> vert;
        indices=solve(pattern+"$"+s);
        reverse(indices.begin(),indices.end());
        for(int i=0;i<=pattern.length()+1;i++){
            indices.pop_back();
        }
        reverse(indices.begin(),indices.end());
        st=-1;
        end=-1;
        for(int i=indices.size()-1;i>=0;i--){
            if(indices[i]==len){
                cout<<i<<endl;
                st=i;
                end=st-len+1;
            }
            if(i<=st && i>=end){
                vert[i]=true;
            }
        }
        

        
        
        vector<vector<int>> v1(n,vector<int>(m,0));
        vector<vector<int>> v2(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v1[i][j]=(i)*m+j;
            }   
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                v2[i][j]=j*n+i;
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[v1[i][j]]=v2[i][j];
            }   
        }
        
       int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int row=(i)*m+j;
                int col=mp[row];
                // cout<<row<<" "<<col<<endl;
                if(hori[row]==1  && vert[col]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};