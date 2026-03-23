class Solution {
public:
    string  breakPalindrome(string s) {
        if(s.length()==1){
            return "";

        }
        int x=0;
        int n;
        if(s.length()&1){
            n=s.length()-1/2;
        }
        else{
            n=s.length()/2;
        }
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a'){
                if(i==s.length()/2 && s.length()&1){
                    continue;
                }
                s[i]='a';
                flag=true;
                break;
            }
        }
        
        if(!flag){
            s.back()='b';
        }
        return s;
        
    }
};