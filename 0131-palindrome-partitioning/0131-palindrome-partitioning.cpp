class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    string curr="";
    bool check(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string&s){
        if(i==s.length()){
            if(curr==""){
            ans.push_back(v);}
            return;
        }
        curr+=s[i];
        solve(i+1,s);
        if(check(curr)){
            v.push_back(curr);
            string temp=curr;
            curr="";
            solve(i+1,s);
            curr=temp;
            v.pop_back();
        }
        curr.pop_back();

    }
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
        
    }
};