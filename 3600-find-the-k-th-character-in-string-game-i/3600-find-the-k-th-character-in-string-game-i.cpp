class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            int n=s.length();
            for(int i=0;i<n;i++){
                char c=s[i];
                c=char(c+1);
                if(c>'z'){
                    c='a';
                }
                s+=c;
            }

        }
        return s[k-1];
        
    }
};