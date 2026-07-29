class Solution {
public:
    vector<int> q;
    vector<vector<string>> ans;
    int check(int row,int col){
        for(int i=0;i<q.size();i++){
            if(q[i]==col){
                return false;
            }
            if(abs(row-i)==abs(q[i]-col)){
                return false;
            }
        }
        return true;
    }
    void solve(int level,int n){
        if(level==n){
            vector<string> v;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    if(j!=q[i]){
                        s.push_back('.');
                    }
                    else{
                        s.push_back('Q');
                    }
                }
                v.push_back(s);

            }
            ans.push_back(v);
            return;

        }
        for(int i=0;i<n;i++){
            if(check(level,i)){
                q.push_back(i);
                solve(level+1,n);
                q.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        solve(0,n);
        return ans;

        
    }
};