class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        int ln=-1;
        for(auto i:arr){
            m[i]++;
        }
        for(auto i:m){
            if(i.second==i.first){
                ln=i.first;
            }
        }
        return ln;
        
    }
};