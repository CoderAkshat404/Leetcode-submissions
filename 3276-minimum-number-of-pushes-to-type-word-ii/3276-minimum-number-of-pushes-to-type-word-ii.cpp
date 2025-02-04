#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (char c : word) {
            m[c]++;
        }

        int count = 0;
        vector<int> arr;
        for (auto i : m) {
            count++;
            arr.push_back(i.second);
        }

        sort(arr.begin(), arr.end());
        
        if (count <= 8) {
            return word.length();
        } else if (count > 8 && count <= 16) {
            int extra = count -8;
            int sum = 0;
            int i = 0;
            while (extra--) {
                sum += arr[i] * 2;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i];
                i++;
            }
            return sum;
        } else if (count > 16 && count <= 24) {
            int extra = count - 16;
            int sum = 0;
            int i = 0;
            while (extra--) {
                sum += arr[i] * 3;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i] * 2;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i];
                i++;
            }
            return sum;
        } else {
            int extra = count - 24;
            int sum = 0;
            int i = 0;
            while (extra--) {
                sum += arr[i] * 4;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i] * 3;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i] * 2;
                i++;
            }
            for (int p = 0; p < 8; p++) {
                sum += arr[i];
                i++;
            }
            return sum;
        }
    }
};