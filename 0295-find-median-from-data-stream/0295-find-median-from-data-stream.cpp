class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }

    void balance(){
        while(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        while(maxheap.size()>minheap.size()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    void addNum(int num) {
        //minheap
        if(minheap.empty()){
            minheap.push(num);
        }else{
            if(maxheap.empty()){
                minheap.push(num);
               
                balance();
            }else{
                if(maxheap.top()<num){
                    minheap.push(num);
                    balance();
                }else{
                    maxheap.push(num);
                    balance();
                }
            }
        }
        
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return ((double)(minheap.top()+maxheap.top())/2);
        }
        return ((double)(minheap.top()));
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */