class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>m;
        for(int i=0;i<paths.size();i++){
            m[paths[i][0]]=paths[i][1];
        }
        string prev=paths[0][0];
        while(m.find(prev)!=m.end()){
            prev=m[prev];
        }
        return prev;

        
    }
};