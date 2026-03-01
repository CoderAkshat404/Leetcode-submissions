class Solution {
public:
    static bool cmp(int a,int b){
        int x=0;
        int y=0;
        for(int i=0;i<32;i++){
            int bit=(a>>i)&1;
            if(bit==1){
                x++;
            }
        }
        for(int i=0;i<32;i++){
            int bit=(b>>i)&1;
            if(bit==1){
                y++;
            }
        }
        if(x==y){
            return a<=b;
        }
        return x<=y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
        
    }
};