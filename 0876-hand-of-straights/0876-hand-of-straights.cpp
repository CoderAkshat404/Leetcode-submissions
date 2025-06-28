class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> m;
        for(auto i:hand){
            m.insert(i);
        }
        if(hand.size()%groupSize!=0){
            return false;
        }
   
        int x=hand.size()/groupSize;
        for(int i=0;i<x;i++){
            vector<int> v;
            for(int j=0;j<groupSize;j++){
                if(v.size()==0){
                    v.push_back(*m.begin());
                    
                    m.erase(m.find(v.back()));
                }
                else{
                    if(m.find(v.back()+1)==m.end()){
                        return false;
                    }
                    else{
                        v.push_back(v.back()+1);
                        m.erase(m.find(v.back()));
                    }
                }
            }
           

        }
        return true;
        
    }
};