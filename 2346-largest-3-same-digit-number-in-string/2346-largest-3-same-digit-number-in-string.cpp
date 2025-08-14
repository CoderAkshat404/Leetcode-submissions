class Solution {
public:
    string largestGoodInteger(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                if(ans==""){
                    ans=s.substr(i,3);
                }
                else{
                    string p=s.substr(i,3);
                    ans=max(ans,p);
                }
            }
        }
        return ans;
    }
};