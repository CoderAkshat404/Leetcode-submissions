#include<bits/stdc++.h>
class KthSmallestSegmentTree{public:struct Node{int count;Node(int m=0):count(m){}};std::vector<Node>tree;int range_size,value_offset;KthSmallestSegmentTree(int min_val,int max_val){if(min_val>max_val)throw;value_offset=-min_val;range_size=max_val-min_val+1;tree.resize(4*range_size);}
void add(int v){add_recursive(1,v+value_offset,0,range_size-1);} void remove(int v){remove_recursive(1,v+value_offset,0,range_size-1);} int findkth(int k){int t=tree[1].count;if(t==0)throw std::runtime_error("E");k=k>t?t:k<1?1:k;return findkth_recursive(1,0,range_size-1,k)-value_offset;}
Node merge(const Node&a,const Node&b){return Node(a.count+b.count);} void add_recursive(int i,int v,int l,int r){if(l==r){tree[i].count++;return;}int m=l+(r-l)/2;if(v<=m)add_recursive(2*i,v,l,m);else add_recursive(2*i+1,v,m+1,r);tree[i]=merge(tree[2*i],tree[2*i+1]);}
void remove_recursive(int i,int v,int l,int r){if(l==r){if(tree[i].count>0)tree[i].count--;return;}int m=l+(r-l)/2;if(v<=m)remove_recursive(2*i,v,l,m);else remove_recursive(2*i+1,v,m+1,r);tree[i]=merge(tree[2*i],tree[2*i+1]);}
int findkth_recursive(int i,int l,int r,int k){if(l==r)return l;int m=l+(r-l)/2;if(k<=tree[2*i].count)return findkth_recursive(2*i,l,m,k);return findkth_recursive(2*i+1,m+1,r,k-tree[2*i].count);}};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int x=nums.size()+1;
        KthSmallestSegmentTree sg(-1e5,1e5);
        for(auto i:nums){
            sg.add(i);
        }
        return sg.findkth(x-k);

         
    }
};