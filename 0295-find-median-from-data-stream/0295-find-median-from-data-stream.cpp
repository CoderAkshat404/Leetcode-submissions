#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int, int>, 
    null_type, 
    less<pair<int, int>>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> pbds;

class MedianFinder {
public:
    pbds m;
    int cnt;

    MedianFinder() {
        cnt = 0;
    }

    void addNum(int num) {
        m.insert({num, cnt++});
    }

    double findMedian() {
        int n = m.size();
        if (n & 1) {
            // odd size: middle element
            pair<int, int> p = *m.find_by_order(n / 2);
            return (double)p.first;
        } else {
            // even size: average of two middle elements
            pair<int, int> p1 = *m.find_by_order(n / 2 - 1);
            pair<int, int> p2 = *m.find_by_order(n / 2);
            return (p1.first + p2.first) / 2.0;
        }
    }
};
