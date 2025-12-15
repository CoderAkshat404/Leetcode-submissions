class Solution {
public:
    int solve(string s){
        int v=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'  || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u'){
                v++;

            }
        }
        return v;
    }
    string reverseWords(string s) {
        vector<string> v;
        string p="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                p+=s[i];
            }
            else{
                v.push_back(p);
                p="";
            }
        }
        v.push_back(p);
        int vc=solve(v[0]);
        string ans=v[0];
        ans+=" ";
        for(int i=1;i<v.size();i++){
            if(solve(v[i])!=vc){
                
                ans+=v[i];
            }
            else{
                reverse(v[i].begin(),v[i].end());
                ans+=v[i];

            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
        
    }
};