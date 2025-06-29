class Solution {
public:
    vector<int> kmp(string s){
        int n=s.length();
        vector<int> kmp(n+1);
        kmp[0]=-1;
        int i=0;
        int j=-1;
        while(i<n){
            while(j!=-1 && s[i]!=s[j]){
                j=kmp[j];
            }
            i++;
            j++;
            kmp[i]=j;
        }
        return kmp;
    }
    string shortestPalindrome(string s) {
        string a=s;
        reverse(a.begin(),a.end());
        vector<int> v=kmp(s+"#"+a);
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        int len=v.back();

        string b=a.substr(0,s.length()-len);
        return b+s;
        
    }
};