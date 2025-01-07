class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    if(words[i].find(words[j])!=string::npos){
                        ans.insert(words[j]);
                    }
                }
            }
        }
        vector<string> r;
        for(auto i:ans){
            r.push_back(i);
            
        }
        return r;
    }
};