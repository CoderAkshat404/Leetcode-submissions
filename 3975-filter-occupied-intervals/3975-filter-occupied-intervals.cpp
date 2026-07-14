class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& o, int fst, int fen) {
        sort(o.begin(),o.end());
        int st=o[0][0];
        int en=o[0][1];
        
        vector<vector<int>> m;
        for(int i=1;i<o.size();i++){
            if(o[i][0]<=en || o[i][0]==en+1){
                en=max(en,o[i][1]);
            }
            else{
                m.push_back({st,en});
                st=o[i][0];
                en=o[i][1];

            }
        }  
        m.push_back({st,en}) ;  
        // for(auto i:m){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        vector<vector<int>> m2;   
        for(int i=0;i<m.size();i++){
            if(m[i][0]>=fst && m[i][1]<=fen){
                m2.push_back({-1,-1});
            }
            else if(fst>m[i][0] && fst<=m[i][1]){
                m2.push_back({m[i][0],fst-1});
                if(fen+1<=m[i][1]){
                    m2.push_back({fen+1,m[i][1]});
                }

            }
            else if(fen>=m[i][0] && fen<m[i][1]){
                m2.push_back({fen+1,m[i][1]});
            }
            else{
                m2.push_back(m[i]);
            }

        }
        vector<vector<int>> ans;
        for(auto i:m2){
            if(i[0]!=-1 && i[1]!=-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};