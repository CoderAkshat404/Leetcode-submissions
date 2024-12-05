class Solution {
public:
    bool canChange(string start, string target) {
        vector<int> v1; // Positions of 'L' in start
        vector<int> v2; // Positions of 'L' in target
        vector<int> v3; // Positions of 'R' in start
        vector<int> v4; // Positions of 'R' in target
        
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L') v1.push_back(i);
            else if (start[i] == 'R') v3.push_back(i);
        }
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == 'L') v2.push_back(i);
            else if (target[i] == 'R') v4.push_back(i);
        }
        
        // Check if 'L' counts or 'R' counts mismatch
        if (v1.size() != v2.size() || v3.size() != v4.size()) return false;
        
        // Validate 'L' positions
        for (int i = 0; i < v1.size(); i++) {
            if (v2[i] > v1[i]) return false; // 'L' can't move right
            if (v1[i] > v2[i]) {
                // Ensure no 'R' blocks 'L' in between
                for (int j = v2[i]; j < v1[i]; j++) {
                    if (start[j] == 'R') return false;
                }
            }
        }
        
        // Validate 'R' positions
        for (int i = 0; i < v3.size(); i++) {
            if (v4[i] < v3[i]) return false; // 'R' can't move left
            if (v3[i] < v4[i]) {
                // Ensure no 'L' blocks 'R' in between
                for (int j = v3[i] + 1; j <= v4[i]; j++) {
                    if (start[j] == 'L') return false;
                }
            }
        }
        
        // Ensure the relative order of 'R' and 'L' matches
        int startRCount = 0, targetRCount = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'R') startRCount++;
            else if (start[i] == 'L') break;
        }
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == 'R') targetRCount++;
            else if (target[i] == 'L') break;
        }
        
        return startRCount == targetRCount;
    }
};
