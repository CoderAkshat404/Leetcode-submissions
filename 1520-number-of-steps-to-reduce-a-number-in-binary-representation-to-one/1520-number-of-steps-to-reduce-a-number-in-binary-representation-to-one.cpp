class Solution {
public:
    bool check(string&s){
        int cnt=0;
        int n=s.length();
        for(auto i:s){
            if(i=='0'){
                cnt++;
            }
        }
        if(cnt==n-1 && s.back()=='1') return true;
        else return false;
    }
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            if(s.back()=='0'){
                s.pop_back();
                ans++;
            }
            else{
                int n=s.length();
                int idx=-1;
                for(int i=n-1;i>=0;i--){
                    if(s[i]=='0'){
                        idx=i;
                        break;
                    }
                }
                if(idx==-1){
                    ans++;
                    ans+=s.length();
                    break;
                }
                s[idx]='1';
                for(int i=idx+1;i<n;i++){
                    s[i]='0';
                }
                ans++;
            }
        }
        return ans;

        
    }
};