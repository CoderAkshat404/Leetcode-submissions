class Solution {
public:
    int bestClosingTime(string s) {
        vector<int> yes;
        vector<int> no;
        int yc=0;
        int nc=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='Y'){
                yc++;
            }
            else{
                nc++;
            }
            yes.push_back(yc);
            no.push_back(nc);

        }
        if(yc==s.length()){
            return s.length();
        }
        if(nc==s.length()){
            return 0;
        }
        int mini=1e9;
        int ans=-1;
        for(int i=0;i<s.length();i++){
            int x=0;
            int y=0;
            if(i-1>=0){
                x=no[i-1];
            }
            if(i-1>=0){
                y=yes.back()-yes[i-1];
            }
            else{
                y=yes.back();
            }
            int z=0;
            if(s[i]=='Y'){
                z=1;
            }
           
            if(x+y+z<mini){
                mini=x+y+z;
                ans=i;
            }
        }
        int x=no.back();
        if(x<mini){
            return s.length();
        }
        return ans;
        
    }
};