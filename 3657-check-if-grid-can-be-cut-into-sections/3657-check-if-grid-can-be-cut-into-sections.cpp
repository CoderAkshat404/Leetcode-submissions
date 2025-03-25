class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int count=0;
        vector<vector<int>> hori;
        vector<vector<int>> vert;
        for(int i=0;i<rectangles.size();i++){
            hori.push_back({rectangles[i][0],rectangles[i][2]});
            vert.push_back({rectangles[i][1],rectangles[i][3]});
        }
        sort(hori.begin(),hori.end());
        for(int i=1;i<hori.size();i++){
            if(hori[i][0]>=hori[i-1][1]){
                count++;
            }
            else{
                hori[i][1]=max(hori[i][1],hori[i-1][1]);
            }
        }
        if(count>=2){
            return true;
        }
        count=0;
        sort(vert.begin(),vert.end());
        for(int i=1;i<vert.size();i++){
            if(vert[i][0]>=vert[i-1][1]){
                count++;
            }
            else{
                vert[i][1]=max(vert[i][1],vert[i-1][1]);
            }
        }
        if(count>=2){
            return true;
        }
        return false;

        
    }
};