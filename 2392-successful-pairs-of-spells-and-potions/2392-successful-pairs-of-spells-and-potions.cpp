class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
            long long x=(success+spells[i]-1)/spells[i];
            int a=lower_bound(potions.begin(),potions.end(),x)-potions.begin();
            if(a<potions.size()){
                ans.push_back(potions.size()-a);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};