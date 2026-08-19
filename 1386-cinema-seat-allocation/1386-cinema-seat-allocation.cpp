class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int total=2*n;
        map<int,vector<int>> m;
        for(auto i:reservedSeats){
            if(i[1]==1 || i[1]==10){
                continue;
            }
            m[i[0]].push_back(i[1]);
        }
        for(auto i:m){
            bool flag1=true;
            bool flag2=true;
            bool flag3=true; 
            for(auto j:i.second){
                if(j>=2 && j<=5){
                    flag1=false;
                    break;
                }
            }
            for(auto j:i.second){
                if(j>=4 && j<=7){
                    flag2=false;
                    break;
                }
            }
            for(auto j:i.second){
                if(j>=6 && j<=9){
                    flag3=false;
                    break;
                }
            }
            if(flag1 || flag2 || flag3){
                total--;
            }
            else{
                total-=2;
            }
        }
        return total;


        
    }
};