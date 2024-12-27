class Solution {
public:
    int check(int m,vector<int>& grades){
        long  long count=1;
        long long  c=0;
        long long  sprev=0;
        long long csum=0;
        long long x=0;
        for(int i=0;i<grades.size();i++){
            csum+=grades[i];
            c++;
            if(c==count){
                c=0;
                count++;
                if(csum<sprev){
                    return 0;
                }
                else{
                    sprev=csum;
                    x++;
                }
            }
        }
        if(x>=m){
            return 1;
        }
        else{
            return 0;
        }
    }
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int lo=0;
        int hi=grades.size();
        int ans=0;
        while(lo<=hi){
            int m=lo+(hi-lo)/2;
            if(check(m,grades)==1){
                lo=m+1;
                ans=m;
            }
            else{
                hi=m-1;
            }
        }
        return ans;        
    }
};