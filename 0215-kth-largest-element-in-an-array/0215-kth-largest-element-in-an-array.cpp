#include<bits/stdc++.h>
class KthSmallestSegmentTree {
public:
    struct Node {
        int count;
        Node(int m = 0) : count(m) {}
    };

    std::vector<Node> tree;
    int range_size;
    int value_offset;

    KthSmallestSegmentTree(int min_val, int max_val) {
        if (min_val > max_val) {
            throw std::invalid_argument("min_val cannot be greater than max_val");
        }
        value_offset = -min_val;
        range_size = max_val - min_val + 1;
        tree.resize(4 * range_size, Node(0));
    }

    Node merge(const Node& a, const Node& b) {
        return Node(a.count + b.count);
    }

    void add_recursive(int index, int val_idx, int l, int r) {
        if (l == r) {
            tree[index].count++;
            return;
        }
        int mid = l + (r - l) / 2;
        if (val_idx <= mid) add_recursive(2 * index, val_idx, l, mid);
        else add_recursive(2 * index + 1, val_idx, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void add(int val) {
        add_recursive(1, val + value_offset, 0, range_size - 1);
    }

    void remove_recursive(int index, int val_idx, int l, int r) {
        if (l == r) {
            if (tree[index].count > 0) tree[index].count--;
            return;
        }
        int mid = l + (r - l) / 2;
        if (val_idx <= mid) remove_recursive(2 * index, val_idx, l, mid);
        else remove_recursive(2 * index + 1, val_idx, mid + 1, r);
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    void remove(int val) {
        remove_recursive(1, val + value_offset, 0, range_size - 1);
    }



    int findkth_recursive(int index, int l, int r, int k) {
        if (l == r) return l;
        int mid = l + (r - l) / 2;
        int left_count = tree[2 * index].count;
        if (k <= left_count) return findkth_recursive(2 * index, l, mid, k);
        else return findkth_recursive(2 * index + 1, mid + 1, r, k - left_count);
    }

    int findkth(int k) {
        int total_elements = tree[1].count;
        if (total_elements == 0) {
            throw std::runtime_error("Cannot find kth element in an empty tree.");
        }
        if (k > total_elements) k = total_elements;
        if (k < 1) k = 1;
        int result_index = findkth_recursive(1, 0, range_size - 1, k);
        return result_index - value_offset;
    }
};
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