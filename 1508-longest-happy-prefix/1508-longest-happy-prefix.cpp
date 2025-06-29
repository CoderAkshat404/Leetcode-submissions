class Solution {
public:
    vector<int> builtkmp(string&s){
        int n=s.length();
        vector<int> kmp(n+1);
        kmp[0]=-1;
        int i=0;
        int j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j=kmp[j];

            } 
            j++;
            i++;
            kmp[i]=j;
        }
        return kmp;
    }
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> kmp=builtkmp(s);
        for(auto i:kmp){
            cout<<i<<" ";
        }
        int maxi=kmp.back();
        if(maxi==0){
            return "";
        }
        return s.substr(0,maxi);
        
    }
};