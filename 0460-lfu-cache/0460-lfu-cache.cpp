class LFUCache {
public:
    int lfu=0;
    int size,c;
    unordered_map<int,pair<int,int>> cache;
    unordered_map<int,list<int>> fk;
    unordered_map<int,list<int>::iterator> iter;
    LFUCache(int capacity) {
        c=capacity;
        size=0;
        
    }
    void touch(int key){
        int oldf=cache[key].second;
        auto it=iter[key];
        fk[oldf].erase(it);
        cache[key].second++;
        fk[oldf+1].push_back(key);
        if(fk[lfu].empty()){
            lfu++;
        }
        iter[key]=--fk[oldf+1].end();
    }
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        int val=cache[key].first;
        touch(key);
        return val;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key].first=value;
            touch(key);
        }
        else{
            if(c==size){
                int k=fk[lfu].front();
                cache.erase(k);
                iter.erase(k);
                fk[lfu].pop_front();

            }
            else{
                size++;
            }
            cache[key]={value,1};
            lfu=1;
            fk[1].push_back(key);
            iter[key]=--fk[1].end();
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */