class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=0;
        bool flag=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                flag=true;
                n++;
            }
            if(s[i]==' ' && flag==true){
                break;
            }

        }
        return n;
        
    }
};