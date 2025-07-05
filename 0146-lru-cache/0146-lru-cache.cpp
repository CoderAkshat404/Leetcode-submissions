class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }

};
class LRUCache {
public:
    int capa;
    unordered_map<int,Node*> m;
    Node *head;
    Node *tail;
    void insertAfterHead(Node *node){
        Node *nodeja=head->next;
        head->next=node;
        node->prev=head;
        node->next=nodeja;
        nodeja->prev=node;
    }
    void deletenode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->prev=NULL;
        node->next=NULL;
    }


    LRUCache(int capacity) {
        capa=capacity;
        head=new Node(1,1);
        tail=new Node(1,1);
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* node=m[key];
        deletenode(node);
        insertAfterHead(node);
        return node->value;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            if(m.size()==capa){
                Node* node=tail->prev;
                m.erase(node->key);
                deletenode(node);
                delete node;
                Node* node2=new Node(key,value);
                m[key]=node2;
                insertAfterHead(node2);
                
            }
            else{
            Node* node2 = new Node(key, value);
            m[key] = node2;
            insertAfterHead(node2);}

        }
        Node* node=m[key];
        node->value=value;
        deletenode(node);
        insertAfterHead(node);
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */