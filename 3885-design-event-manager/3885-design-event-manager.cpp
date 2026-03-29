class EventManager {
public:
    map<int,int> m;
    set<pair<int,int>> s;
    void printer(){
        for(auto i:s){
            cout<<i.first<<" "<<i.second<<"}";
        }
        cout<<endl;
    } 
    EventManager(vector<vector<int>>& events) {
        for(auto i:events){
            m[i[0]]=i[1];
            s.insert({i[1],-i[0]});
        }
        
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        int b=m[eventId];
        s.erase({b,-eventId});
        s.insert({newPriority,-eventId});
        m[eventId]=newPriority;
        

        
    }
    
    int pollHighest() {
        if(s.empty()){
            return -1;
        }
       pair<int,int> p=*s.rbegin();
       s.erase(p);
       return -p.second;
       
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */