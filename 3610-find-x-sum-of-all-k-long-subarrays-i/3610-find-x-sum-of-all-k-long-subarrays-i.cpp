class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first == b.first)
                return a.second < b.second; 
            return a.first < b.first;       
        }
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> m;
            for (int j = i; j < i + k; j++) {
                m[nums[j]]++;
            }

            priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
            for (auto& p : m) {
                pq.push({p.second, p.first});
            }

            int sum = 0;
            for (int j = 0; j < x && !pq.empty(); j++) {
                sum += pq.top().second * pq.top().first;
                pq.pop();
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
