class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        for(int i=0;i<m;i++){
            p[i]=i+1;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int posi=-1;
            for(int j=0;j<m;j++){
                if(p[j]==queries[i]){
                    posi=j;
                    break;
                }
                
            }
            ans.push_back(posi);
            vector<int> new1;
            new1.push_back(queries[i]);
            for(int j=0;j<m;j++){
                if(p[j]!=queries[i]){
                    new1.push_back(p[j]);
                }
            }
            p=new1;

            
        }
        return ans;
    }
};