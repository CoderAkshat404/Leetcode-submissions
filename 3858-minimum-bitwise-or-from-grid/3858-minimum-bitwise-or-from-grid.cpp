class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int curr0=0;
        for(int i=31;i>=0;i--){
            int temp=curr0 |(1<<i);
            bool possible=true;
            for(auto r:grid){
                bool foundhere=false;
                for(auto j:r){
                    if((j & temp)==0){
                        foundhere=true;
                        break;

                    }
                }
                if(foundhere==false){
                    possible=false;
                    break;
                }
            }
            if(possible){
                curr0=temp;
            }
            else{
                ans=ans |(1<<i);
            }
        }
        return ans;
        
    }
};