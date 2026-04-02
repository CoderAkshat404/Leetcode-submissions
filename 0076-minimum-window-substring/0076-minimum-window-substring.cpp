class Solution {
public:
    bool check(map<char,int>&curr, map<char,int>& m,char c){
        curr[c]++;
        for(auto i:m){
            if(i.second>curr[i.first]) {
                curr[c]--;
                return false;
            }
        }
        curr[c]--;
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> m;
        for(auto i:t){
            m[i]++;
        }
        int sti=-1;
        int mini=1e9;
        int l=0;
        int r=-1;
        int n=s.length();
        map<char,int> curr;
        while(l<n){
            while(r+1<n && !check(curr,m,s[r+1])){
                r++;
                curr[s[r]]++;
            }
            if(r+1<n && check(curr,m,s[r+1])){
               
                // cout<<"here"<<endl;
                if(r-l+2<mini){
                    mini=r-l+2;
                    sti=l;
                }
            }
            if(l>r){
                l++;
                r=l-1;
            }
            else{
                curr[s[l]]--;
                l++;
            }
        }
        if(sti==-1) return "";
        return s.substr(sti,mini);


        
    }
};