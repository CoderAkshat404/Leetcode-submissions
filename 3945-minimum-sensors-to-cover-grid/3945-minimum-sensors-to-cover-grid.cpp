class Solution {
public:
    int minSensors(int n, int m, int k) {
        int rows=ceil((double)n/(2*k+1));
        int cols=ceil((double)m/(2*k+1));
        return rows*cols;
        
    }
};