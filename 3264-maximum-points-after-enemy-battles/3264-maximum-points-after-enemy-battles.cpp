class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long x=currentEnergy;
        if(currentEnergy==0){
            return 0;
        }
        long long ans=0;
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currentEnergy){
            return 0;
        }
        for(int i=1;i<enemyEnergies.size();i++){
            x+=enemyEnergies[i];
        }
        return x/enemyEnergies[0];
        
    }
};