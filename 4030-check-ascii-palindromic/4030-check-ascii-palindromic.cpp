class Solution {
public:
    string tobin(int n){
        string s="";
        for(int i=0;i<8;i++){
            if((n>>i)&1){
                s+='1';
            }
            else{
                s+='0';
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool isPalindromic(string s) {
        string f="";
        for(int i=0;i<s.length();i++){
            int x=s[i];
            f+=tobin(x);
        }
        int i=0;
        int j=f.length()-1;
        while(i<j){
            if(f[i]==f[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};