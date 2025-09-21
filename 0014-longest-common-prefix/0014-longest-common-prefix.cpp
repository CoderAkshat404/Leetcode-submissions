class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string,int> m;
        for(int i=0;i<strs.size();i++){
            string p="";
            for(int j=0;j<strs[i].length();j++){
                p+=strs[i][j];
                m[p]++;
            }
        }
        string ans="";
        for(auto i:m){
            if(i.second==strs.size()){
                if(i.first.length()>ans.length()){
                    ans=i.first;
                }
            }
        }
        return ans;
        
    }
};