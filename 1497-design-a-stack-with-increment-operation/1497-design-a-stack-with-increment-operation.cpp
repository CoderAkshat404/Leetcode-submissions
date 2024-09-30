class CustomStack {
public:
    vector<int> v;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
        
        
    }
    
    void push(int x) {
        if(v.size()<size){
            v.push_back(x);

        }
        else
            return;
    }
    
    int pop() {
        if(v.empty()){
            return -1;
        }
        else{
            int top=v[v.size()-1];
            v.pop_back();
            return top;
        }
        
    }
    
    void increment(int k, int val) {
        if(v.size()<k){
            for(int i=0;i<v.size();i++){
                v[i]=v[i]+val;
            }
        }
        else{
            for(int i=0;i<k;i++){
                v[i]=v[i]+val;
            }
        }

        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */