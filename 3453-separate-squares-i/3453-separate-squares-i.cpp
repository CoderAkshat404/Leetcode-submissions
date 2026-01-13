class Solution {
public:
    bool check(long double mid, vector<vector<int>>& squares, long double totarea){
        long double bot = 0;
        for(int i = 0; i < squares.size(); i++){
            int y = squares[i][1];
            int l = squares[i][2];
            long double height = max((long double)0, min((long double)l, mid - y));
            bot += height * l;
        }
        return bot >= totarea / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double lo = 0;
        long double hi = 0;
        long double totarea = 0;

        for(int i = 0; i < squares.size(); i++){
            int y = squares[i][1];
            int l = squares[i][2];
            totarea += (long double)l * l;
            hi = max(hi, (long double)y + l);
        }

        for(int i = 0; i < 60; i++){
            long double mid = (lo + hi) / 2.0;
            if(check(mid, squares, totarea)){
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return (double)((hi + lo) / 2.0);
    }
};
