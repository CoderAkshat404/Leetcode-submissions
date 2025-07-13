class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        multiset<int> s;
        for(auto i:trainers){
            s.insert(i);
        }
        int count=0;
        for(int i=0;i<players.size();i++){
            auto it=s.lower_bound(players[i]);
            if(it!=s.end()){
                int x=*it;
                count++;
                s.erase(s.find(x));
            }
        }
        return count;
        
    }
};