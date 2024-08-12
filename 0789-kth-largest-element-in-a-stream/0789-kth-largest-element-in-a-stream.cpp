#include <queue>
#include <vector>

class KthLargest {
public:
    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    KthLargest(int k, std::vector<int>& nums) {
        n = k;
        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (pq.size() < n) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
