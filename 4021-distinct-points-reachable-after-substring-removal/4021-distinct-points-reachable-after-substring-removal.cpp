class Solution {
public:
    int distinctPoints(string s, int k) {
        map<pair<int,int>,int> m;
        int x=0;
        int y=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                x--;
            }
            if(s[i]=='R'){
                x++;
            }
            if(s[i]=='U'){
                y++;
            }
            if(s[i]=='D'){
                y--;
            }
        }
        for(int i=0;i<k;i++){
            if(s[i]=='L'){
                x++;
            }
            if(s[i]=='R'){
                x--;
            }
            if(s[i]=='U'){
                y--;
            }
            if(s[i]=='D'){
                y++;
            }
        }
        m[{x,y}]++;
        int i=0;
        int j=k-1;
        while(j+1<n){
            if(s[j+1]=='L'){
                x--;
            }
            if(s[j+1]=='R'){
                x++;
            }
            if(s[j+1]=='U'){
                y++;
            }
            if(s[j+1]=='D'){
                y--;
            }
            if(s[i]=='L'){
                x++;
            }
            if(s[i]=='R'){
                x--;
            }
            if(s[i]=='U'){
                y--;
            }
            if(s[i]=='D'){
                y++;
            }
            m[{x,y}]++;
            i++;
            j++;


        }
        return m.size();
        
    }
};