class LRUCache {
public:
    int capacity;
    list<int> dll;
    map<int,pair<int,list<int>::iterator>> m;
    void touch(int x){
        auto it=m[x].second;
        dll.erase(it);
        dll.push_front(x);
        it=dll.begin();
        m[x].second=it;

    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        int x=m[key].first;
        touch(key);
        return x;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key].first=value;
            touch(key);
        }
        else if(dll.size()==capacity){
            int last=dll.back();
            dll.pop_back();
            m.erase(last);
            dll.push_front(key);
            auto it=dll.begin();
            m[key]={value,it};
        }
        else{
            dll.push_front(key);
            auto it=dll.begin();
            m[key]={value,it};
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */