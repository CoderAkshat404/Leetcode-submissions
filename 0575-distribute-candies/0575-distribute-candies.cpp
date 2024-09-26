#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, bool> m;
        int count = 0;

        for (int i = 0; i < candyType.size(); i++) {
            if (m[candyType[i]] == false) {
                count++;
                m[candyType[i]] = true; // Mark this candy type as seen
            }
        }
        
        // Calculate the minimum of half the total candies or the number of unique types
        if(candyType.size()/2<count){
            return candyType.size()/2;
        }
        else{
            return count;
        }
    }
};
