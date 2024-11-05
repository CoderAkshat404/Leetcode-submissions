class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int ans=0;
        char prev=s[0];
        bool prevp=false;
        bool even=false;
        
        for(int i=0;i<s.length();i++){
            if(s[i]==prev){
                count++;
            }
            else{
                if(count&1){
                    ans++;
                    count=2;
                }
                else{
                    count=1;
                }
                prev=s[i];
                

            }
        }
        if(count&1){
                    ans++;
                    count=2;
                }
        
        return ans;
    }
};