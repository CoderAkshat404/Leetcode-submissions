class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            m[t[i]]--;
        }
        char c;
        for(auto i:m){
            if(i.second<0){
                c=i.first;
            }
        }
        return c;


        
    }
};