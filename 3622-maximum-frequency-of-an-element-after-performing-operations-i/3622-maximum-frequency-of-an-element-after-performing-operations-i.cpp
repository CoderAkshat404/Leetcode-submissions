class KthSmallestSegmentTree{public:const long long MIN_VAL=-1e9,MAX_VAL=1e9;struct Node{int count=0;Node*l=nullptr,*r=nullptr;};Node*root=new Node();
void add(int v){add_recursive(root,MIN_VAL,MAX_VAL,v);} void remove(int v){remove_recursive(root,MIN_VAL,MAX_VAL,v);} int findkth(int k){int t=root->count;if(t==0)throw runtime_error("E");k=k>t?t:k<1?1:k;return findkth_recursive(root,MIN_VAL,MAX_VAL,k);} int rankOf(int v){return rank_recursive(root,MIN_VAL,MAX_VAL,v-1);}
void add_recursive(Node*&curr,long long l,long long r,int v){if(!curr)curr=new Node();curr->count++;if(l==r)return;long long m=l+(r-l)/2;if(v<=m)add_recursive(curr->l,l,m,v);else add_recursive(curr->r,m+1,r,v);}
void remove_recursive(Node*curr,long long l,long long r,int v){if(!curr)return;curr->count--;if(l==r)return;long long m=l+(r-l)/2;if(v<=m)remove_recursive(curr->l,l,m,v);else remove_recursive(curr->r,m+1,r,v);}
int findkth_recursive(Node*curr,long long l,long long r,int k){if(l==r)return l;int lc=curr->l?curr->l->count:0;if(k<=lc)return findkth_recursive(curr->l,l,l+(r-l)/2,k);return findkth_recursive(curr->r,l+(r-l)/2+1,r,k-lc);} int rank_recursive(Node*curr,long long l,long long r,int qr){if(!curr||qr<l)return 0;if(r<=qr)return curr->count;long long m=l+(r-l)/2;return rank_recursive(curr->l,l,m,qr)+rank_recursive(curr->r,m+1,r,qr);}};


class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        KthSmallestSegmentTree sg;
        map<int,int> m;
        int ele=0;
        for(auto i:nums){
            sg.add(i);
            m[i]++;
            ele=max(ele,i);
        }
        int maxi=INT_MIN;
        for(int i=0;i<=ele+k;i++){
            int curr=i;
            int ul=sg.rankOf(curr+k+1);
            int ll=sg.rankOf(curr-k);
            int x=ul-ll;
            int ops_needed=x-m[curr];
            int y=min(numOperations,ops_needed);
            maxi=max(maxi,(m[curr]+y));
            
        }
        return maxi;
        
    }
};