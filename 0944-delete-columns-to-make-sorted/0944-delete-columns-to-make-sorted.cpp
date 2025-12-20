class Solution {
public:
    set<int> s;
    int minDeletionSize(vector<string>& strs) {
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]<strs[i-1][j]){
                    s.insert(j);
                }
            }
        }
        return s.size();
        
    }
};