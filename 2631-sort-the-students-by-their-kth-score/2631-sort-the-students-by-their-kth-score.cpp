class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(int p=0;p<score.size()-1;p++){
            for(int i=p+1;i<score.size();i++){
                if(score[p][k]<score[i][k]){
                    for(int j=0;j<score[p].size();j++){
                        swap(score[p][j],score[i][j]);

                    }
                
                }
        }
        }

    return score;    
    }
};