class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while(n!=0){
            int x=n%10;
            v.push_back(x);
            n=n/10;
        }
        sort(v.rbegin(),v.rend());
        return v[0]*v[1];
    }
};