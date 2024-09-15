class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O'|| s[i]=='U'){
                v.push_back(s[i]);
            }
        }
        reverse(v.begin(),v.end());
        string ans="";
        int k=0;
        for(int i=0;i<s.length();i++){
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O'|| s[i]=='U'){
                ans.push_back(v[k]);
                k++;
             }
             else{
                ans.push_back(s[i]);
             }

        }
        return ans;

        
    }
};