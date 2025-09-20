class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
       
        vector<vector<bool>> knows(m, vector<bool>(n+1, false));
        for (int p = 0; p < m; p++) {
            for (int l : languages[p]) {
                knows[p][l] = true;
            }
        }

        int mini = INT_MAX;

      
        for (int i = 1; i <= n; i++) {
            int count = 0;
            unordered_set<int> st;

            for (int j = 0; j < friendships.size(); j++) {
                int u = friendships[j][0];
                int v = friendships[j][1];

             
                bool flag = false;
                for (int l = 1; l <= n; l++) {
                    if (knows[u-1][l] && knows[v-1][l]) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    
                    int x = 2;
                    bool flag1 = true, flag2 = true;

                    if (st.find(u) != st.end()) {
                        flag1 = false;
                        x--;
                    }
                    if (st.find(v) != st.end()) {
                        flag2 = false;
                        x--;
                    }

                    if (knows[u-1][i]) {
                        flag1 = false;
                        x--;
                    }
                    if (knows[v-1][i]) {
                        flag2 = false;
                        x--;
                    }

                    if (flag1) st.insert(u);
                    if (flag2) st.insert(v);

                    count += x;
                }
            }
            mini = min(mini, count);
        }

        return mini;
    }
};
