class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> z;
    
        map<int,int> m;
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
                z.insert(i);
            }
            else{
                if(m.find(rains[i])!=m.end()){
                    int indx=m[rains[i]];
                    auto ub=z.upper_bound(indx);
                    if(ub!=z.end()){
                        rains[*ub]=rains[i];
                        m[rains[i]]=i;
                        z.erase(*ub);
                        rains[i]=-1;
                    }
                    else{
                        return {};
                    }
                }
                else{
                    m[rains[i]]=i;
                    rains[i]=-1;
                }
            }
        }
        for(auto i:z){
            rains[i]=1;
        }
        return rains;
        
    }
};