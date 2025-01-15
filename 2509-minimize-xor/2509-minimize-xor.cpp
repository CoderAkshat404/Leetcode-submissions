class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count1 = 0;
        int ans = 0;

        // Count the number of '1' bits in num2
        for (int i = 0; i < 32; i++) {
            int b = (num2 >> i) & 1;
            if (b == 1) {
                count1++;
            }
        }

        int count2 = 0;
        vector<int> bits;

        // Extract bits of num1 and count '1's
        for (int i = 31; i >= 0; i--) {
            int b = (num1 >> i) & 1;
            if (b == 1) {
                count2++;
            }
            bits.push_back(b);
        }

        if (count1 <= count2) {
            int c = 0;

            // Set bits from num1 to ans until count1 is reached
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] == 1) {
                    ans += (1 << (31 - i)); // Corrected bit position calculation
                    c++;
                    if (c == count1) {
                        break;
                    }
                }
            }

        } else {
            int c = 0;
            for (int i = 0; i < bits.size(); i++) {
                if (bits[i] == 1) {
                    ans += (1 << (31 - i)); 
                    c++;
                }
            }

            
            for (int i = bits.size() - 1; i >= 0; i--) {
                if (bits[i] == 0) {
                    ans += (1 << (31 - i)); 
                    c++;
                    if (c == count1) {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
