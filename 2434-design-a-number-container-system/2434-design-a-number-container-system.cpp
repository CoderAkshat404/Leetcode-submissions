#include <map>
#include <set>
using namespace std;

class NumberContainers {
public:
    map<int, int> m1;  // Stores index -> number
    map<int, set<int>> m2;  // Stores number -> sorted indexes

    NumberContainers() {}

    void change(int index, int number) {
        if (m1.count(index)) {
            int prevNumber = m1[index];
            m2[prevNumber].erase(index); // Remove from previous number's index list
            if (m2[prevNumber].empty()) {
                m2.erase(prevNumber);  // Clean up empty sets
            }
        }
        m1[index] = number;
        m2[number].insert(index);  // Insert into sorted set
    }

    int find(int number) {
        if (m2.count(number) == 0 || m2[number].empty()) {
            return -1;
        }
        return *m2[number].begin(); // Return smallest index
    }
};
