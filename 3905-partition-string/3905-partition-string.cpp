class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> st;
        vector<string> ans;
        string p="";
        for(int i=0;i<s.length();i++){
            p+=s[i];
            if(st.find(p)==st.end()){
                st.insert(p);
                ans.push_back(p);
                p="";
            }
        }
        return ans;
        
        
    }
};