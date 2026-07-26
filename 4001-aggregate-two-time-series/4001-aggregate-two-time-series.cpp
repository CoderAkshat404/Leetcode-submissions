class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<int> s;
        map<int,int> m1;
        map<int,int> m2;
        for(auto i:series1){
            s.insert(i[0]);
            m1[i[0]]=i[1];
        }
        for(auto i:series2){
            s.insert(i[0]);
            m2[i[0]]=i[1];
        }
        vector<vector<int>> ans;
        for(auto i:s){
            
          
            int p=0;
            int q=0;
            auto x=m1.lower_bound(i);
            if(x!=m1.end()){
                p=x->second;
            }
            auto y=m2.lower_bound(i);
            if(y!=m2.end()){
                q=y->second;
            }
            ans.push_back({i,p+q});
        }
        return ans;
        
    }
};