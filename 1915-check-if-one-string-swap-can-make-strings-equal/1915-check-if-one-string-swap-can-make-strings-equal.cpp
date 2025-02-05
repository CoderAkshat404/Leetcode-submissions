class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string a=s1;
        string b=s2;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a!=b){
            return false;
        }
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        if(count>2){
            return false;
        }
        return true;
        
    }
};