#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
            return (double)(m.find_by_order((n - 1) / 2)->first);
        } else {
            int x = m.find_by_order(n / 2)->first;
            int y = m.find_by_order(n / 2 - 1)->first;
            return ((double)(x + y)) / 2;
        }
    }
};
