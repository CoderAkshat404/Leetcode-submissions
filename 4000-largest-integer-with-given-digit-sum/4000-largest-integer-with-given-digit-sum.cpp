class Solution {
public:
    int largestInteger(int n, int s) {
        string ans="";
        for(int i=0;i<n;i++){
            int x=min(9,s);
            ans+=(x+'0');
            s-=x;
        }
        if(s>0) return -1;
        return stoi(ans);
        
    }
};