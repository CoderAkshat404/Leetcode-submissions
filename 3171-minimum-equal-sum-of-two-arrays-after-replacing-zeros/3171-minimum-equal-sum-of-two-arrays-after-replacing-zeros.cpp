class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2) {
        long long int suma=0;
        long long int sumb=0;
        for(int i=0;i<num1.size();i++){
            suma+=num1[i];
        }
        for(int i=0;i<num2.size();i++){
            sumb+=num2[i];
        }
        long long int count0a=count(num1.begin(),num1.end(),0);
        long long int count0b=count(num2.begin(),num2.end(),0);
        if(suma==sumb){
            if((count0a>0 && count0b>0) || (count0a==0 && count0b==0)){
                return suma+max(count0a,count0b);
            }
            else return -1;
        }
        suma+=count0a;
        sumb+=count0b;
        if(suma>sumb){
            int d=suma-sumb;
            if(d>0 && count0b==0) return -1;
            else{
                return suma;
            }
        }
        else{
            int d=sumb-suma;
            if(d>0 && count0a==0) return -1;
            else{
                return sumb;
            }
        

        }

        
    }
};