class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // Edge case when numRows is 1

        vector<vector<char>> v(numRows, vector<char>(1000, ' '));  // Adjusted size of inner vectors
        int i = 0, j = 0, count = 0;
        while (count < s.length() ) {
            while (i < numRows && count < s.length() ) {  // Move down
                
                v[i][j] = s[count];
                count++;
                i++;
            }
            i -= 2;  // Adjust to correct position for upward traversal
            j++;  // Move right
            while (i > 0 && count < s.length()) {  // Move up
               
                v[i][j] = s[count];
                i--;
                j++;
                count++;
            }
             // Adjust to correct position for downward traversal
              // Adjust to correct position for downward traversal
        }

        string p = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] != ' ') {
                    p += v[i][j];
                }
            }
        }
        return p;
    }
};
