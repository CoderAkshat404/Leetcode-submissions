class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m1;
         unordered_map<int,int> m2;

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            if(m1[x]>=1){
                m2[m1[x]]--;
                if(m2[m1[x]]<=0){
                    m2.erase(m1[x]);
                }

            }
            m1[x]=y;
            m2[y]++;


            ans.push_back(min(m1.size(),m2.size()));    
        }
        return ans;
        
    }
};