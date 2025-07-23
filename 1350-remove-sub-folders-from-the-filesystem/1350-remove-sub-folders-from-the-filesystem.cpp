class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        string prev=folder[0]+'/';
        for(int i=1;i<folder.size();i++){
            if(folder[i].find(prev)==string::npos || folder[i].find(prev)>1 ){
                ans.push_back(folder[i]);
                prev=folder[i]+'/';
            }
        }
        return ans;
        
    }
};