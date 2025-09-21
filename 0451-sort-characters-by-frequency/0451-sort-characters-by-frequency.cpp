class Solution {
public:
    static unordered_map<char,int> m;

    static bool cmp(char a,char b){
        if(m[a]==m[b]) return a > b;
        return m[a] > m[b];
    }

    string frequencySort(string s) {
        m.clear();
        for(char c : s) m[c]++;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

unordered_map<char,int> Solution::m; 
