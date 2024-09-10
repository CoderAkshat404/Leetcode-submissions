class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> v;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                v.push_back(i);
                v.push_back(num/i);
            }
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        if(num==1){
            return false;
        }
        if(sum+1==num){
            return true;
        }
        else{
            return false;
        }
        
    }
};