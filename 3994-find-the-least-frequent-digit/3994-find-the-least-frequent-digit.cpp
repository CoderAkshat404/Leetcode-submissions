class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int> m;
        while(n!=0){
            int x=n%10;
            m[x]++;
            n=n/10;
        }
        int min_f=1e9;
        int mini=1e9;
        for(auto i:m){
            if(i.second<min_f){
                min_f=i.second;
                mini=i.first;
            }
        }
        return mini;
        
    }
};