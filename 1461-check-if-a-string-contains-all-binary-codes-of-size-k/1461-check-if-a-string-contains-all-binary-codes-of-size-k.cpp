class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()){
            return false;
        }
        set<string> st;
        string curr="";
        for(int i=0;i<k;i++){
            curr+=s[i];
        }
        st.insert(curr);
        int i=0;
        int j=k-1;
        while(j+1<s.length()){
            curr+=s[j+1];
            curr.erase(curr.begin());
            st.insert(curr);
            i++;
            j++;
        }
        return st.size()==(1<<k);
        
    }
};