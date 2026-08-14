class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            map<int,int> m;
            for(int j=i;j<n;j++){
                if(m[s[j]]==2){
                    maxi=max(maxi,j-i);
                    break;
                }
                maxi=max(maxi,j-i+1);
                m[s[j]]++;
            }
        }
        return maxi;
        
    }
};