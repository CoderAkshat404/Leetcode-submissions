class Solution {
public:
    vector<string> ans;
    string curr;
    void solve(int i,int n){
        if(i==n){
            int cnt=0;
            for(int j=0;j<curr.size();j++){
                if(curr[j]=='('){
                    cnt++;
                }
                else{
                    cnt--;
                    if(cnt<0){
                        return;
                    }
                }
            }
            if(cnt!=0) return;
            ans.push_back(curr);
            return;
        }
        curr.push_back('(');
        solve(i+1,n);
        curr.pop_back();
        curr.push_back(')');
        solve(i+1,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        solve(0,2*n);
        return ans;
        
    }
};