class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int i=0;
        int j=s.length()-1;
        int sum=0;
        while(i<j){
            string p="";
            p+=s[i];
            p+=s[j];
            sum+=stoi(p);
            i++;
            j--;
            
        }
        return sum;
        
    }
};