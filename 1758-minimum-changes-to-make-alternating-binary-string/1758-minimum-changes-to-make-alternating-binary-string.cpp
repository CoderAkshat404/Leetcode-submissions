class Solution {
public:
    int minOperations(string s) {
        int curr=0;
        int x=0;
        for(int i=0;i<s.length();i++){
            if(s[i]-'0'!=curr){
                x++;
            }
            curr=1-curr;
        }
        curr=1;
        int y=0;
        for(int i=0;i<s.length();i++){
            if(s[i]-'0'!=curr){
                y++;
            }
            curr=1-curr;
        }
        return min(x,y);

        
    }
};