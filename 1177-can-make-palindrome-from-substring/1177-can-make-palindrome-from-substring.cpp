class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int> xori(n);
        for(int i=0;i<n;i++){
            int num=0;
            num+=(1<<(s[i]-'a'));
            if(i>0){
                xori[i]=(xori[i-1]^num);
            }
            else{
                xori[i]=num;
            }
        }
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int x=0;
            if(l-1>=0){
                x=(xori[r]^xori[l-1]);
            }
            else{
                x=xori[r];
            }
            int cnt=0;
            for(int j=0;j<32;j++){
                int b=((x>>j)&1);
                if(b==1){
                    cnt++;
                }
            }
            ans[i] = (cnt / 2) <= k;
        }
        return ans;
        
    }
};