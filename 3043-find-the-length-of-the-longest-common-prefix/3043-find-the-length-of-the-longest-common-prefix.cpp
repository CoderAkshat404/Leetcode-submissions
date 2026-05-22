class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi=0;
        set<string> st;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string temp="";
            for(int j=0;j<s.length();j++){
                temp+=s[j];
                st.insert(temp);
            }
        }
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string temp="";
            for(int j=0;j<s.length();j++){
                temp+=s[j];
                if(st.find(temp)!=st.end()){
                    maxi=max(maxi,(int)temp.length());
                }
                
            }
            
        }
        return maxi;

        
    }
};