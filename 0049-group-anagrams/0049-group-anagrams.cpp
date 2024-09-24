class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> a=strs;
        for(int i=0;i<a.size();i++){
            sort(a[i].begin(),a[i].end());
        }
        unordered_map<string,bool> m;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            if(m[strs[i]]==true){
                continue;
            }
            vector<string> v;
            for(int j=0;j<strs.size();j++){
                if(a[i]==a[j]){
                    v.push_back(strs[j]);
                    m[strs[j]]=true;
                }

            }
            ans.push_back(v);
        }
        
        return ans;
    }
};