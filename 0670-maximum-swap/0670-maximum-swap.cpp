class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string a = s;
        sort(a.rbegin(), a.rend());
        
        // Check if any swap is needed
        int i = 0;
        while (i < s.length() && s[i] == a[i]) {
            i++;
        }
        
        if (i == s.length()) {
            // The number is already the largest possible
            return num;
        }
        
        // Find the correct position to swap
        int corr = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == a[i]) {
                corr = j;
                break;
            }
        }
        
        // Perform the swap
        swap(s[i], s[corr]);
        return stoi(s);
    }
};
