class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long curr=1;
        for(int i=0;i<n;i++){
           curr=*s.begin();
            s.erase(curr);
            s.insert(curr*2*1LL);
            s.insert(curr*3*1LL);
            s.insert(curr*5*1LL);
        }
        return (int)curr;
        
    }
};