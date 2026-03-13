class Solution {
public:
    vector<int> fact;
    string ans="";
    void solve(set<char>&s,int n, int k){
        int sum=0;
        for(auto i:s){
            if(k<=fact[n-1]+sum){
                ans+=i;
                s.erase(i);
                solve(s,n-1,k-sum);
                return;
            }
        
            sum+=fact[n-1];
            

        }

    }
    string getPermutation(int n, int k) {
        set<char> s;
        for(char ch='1';ch<=char(n+'0');ch++){
            s.insert(ch);
        }
        int pro=1;
        fact.push_back(pro);
        for(int i=1;i<=n;i++){
            pro*=i;
            fact.push_back(pro);

        }
        solve(s,n,k);
        return ans;
        
    }
};