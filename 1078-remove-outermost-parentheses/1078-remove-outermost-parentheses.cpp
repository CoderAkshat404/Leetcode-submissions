class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                int x=1;
                int j=i+1;
                while(x!=0){
                    if(s[j]==')'){
                        x--;
                    }
                    if(s[j]=='('){
                        x++;
                    } 
                    if(x!=0){
                        ans+=s[j];
                        j++; 
                    } 
                      
                }
                i=j;
            }
        }
      return ans;  
    }
};