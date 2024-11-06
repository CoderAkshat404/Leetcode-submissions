class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        char prev=s[0];
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]==prev){
                count++;
            }
            else{
                if(count>=2){
                    ans+=prev;
                    ans+=prev;

                }
                else{
                    ans+=prev;
                }
                count=1;
                prev=s[i];
            }
        }
        if(count>=2){
                    ans+=prev;
                    ans+=prev;

                }
                else{
                    ans+=prev;
                }
        return ans;
    }
};