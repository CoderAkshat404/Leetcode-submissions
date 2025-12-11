class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,int> r;
        map<int,int> c;
        for(int i=0;i<buildings.size();i++){
            r[buildings[i][0]]++;
            c[buildings[i][1]]++;

        }
        sort(buildings.begin(),buildings.end());
        map<int,int> rc;
        map<int,int> cc;
        map<int,bool> rs;
        map<int,bool> cs;
        int ans=0;
        for(int i=0;i<buildings.size();i++){
            rc[buildings[i][0]]++;
            cc[buildings[i][1]]++;
            if(r[buildings[i][0]]-rc[buildings[i][0]]>0 && c[buildings[i][1]]-cc[buildings[i][1]]>0 && rs[buildings[i][0]]==true && cs[buildings[i][1]]==true){
                ans++;
            }
            rs[buildings[i][0]]=true;
            cs[buildings[i][1]]=true;

        }

        return ans;
    }
};