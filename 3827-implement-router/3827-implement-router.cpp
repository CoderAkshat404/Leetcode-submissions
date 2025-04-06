#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    int memoryLimit;
    queue<tuple<int, int, int>> packets;
    unordered_set<string> seen;
    unordered_map<int, deque<int>> destTimestamps;

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    string makeKey(int src, int dst, int ts) {
        return to_string(src) + "," + to_string(dst) + "," + to_string(ts);
    }

    bool addPacket(int src, int dst, int ts) {
        string key = makeKey(src, dst, ts);
        if (seen.count(key)) return false;

        if (packets.size() >= memoryLimit) {
            auto [oldSrc, oldDst, oldTs] = packets.front();
            packets.pop();
            string oldKey = makeKey(oldSrc, oldDst, oldTs);
            seen.erase(oldKey);
            destTimestamps[oldDst].pop_front();
        }

        packets.emplace(src, dst, ts);
        seen.insert(key);
        destTimestamps[dst].push_back(ts);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        auto [src, dst, ts] = packets.front();
        packets.pop();
        string key = makeKey(src, dst, ts);
        seen.erase(key);
        destTimestamps[dst].pop_front();
        return {src, dst, ts};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination)) return 0;
        const auto &dq = destTimestamps[destination];
        auto low = lower_bound(dq.begin(), dq.end(), startTime);
        auto high = upper_bound(dq.begin(), dq.end(), endTime);
        return distance(low, high);
    }
};