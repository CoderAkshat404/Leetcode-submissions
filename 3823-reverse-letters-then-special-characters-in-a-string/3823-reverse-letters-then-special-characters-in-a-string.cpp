class Solution {
public:
    string reverseByType(string s) {
        vector<char> l;
        vector<char> sp;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                l.push_back(s[i]);
            }
            else{
                sp.push_back(s[i]);
            }
        }
        reverse(sp.begin(),sp.end());
        reverse(l.begin(),l.end());
        int k=0;
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                s[i]=l[k];
                k++;
            }
            else{
                s[i]=sp[j];
                j++;
            }

        }
        return s;
        
    }
};