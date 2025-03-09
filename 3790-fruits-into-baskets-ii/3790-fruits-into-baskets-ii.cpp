class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int,int> m;
        int n=fruits.size();
        int count=0;
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && m[j]==false){
                    flag=true;
                    m[j]=true;
                    break;
                }
            }
            if(flag==false){
                count++;
            }
        }
        return count;
        
    }
};