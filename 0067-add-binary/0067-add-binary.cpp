class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int j=0;
        while(i<a.length() && j<b.length()){
            int n=(a[i]-'0')+(b[j]-'0')+carry;
            ans+=(((n>>0)&1)+'0');
            carry=((n>>1)&1);
            i++;
            j++;

        }
        while(i<a.length()){
            int n=(a[i]-'0')+carry;
            ans+=(((n>>0)&1)+'0');
            carry=((n>>1)&1);
            i++;
        }
        while(j<b.length()){
            int n=(b[j]-'0')+carry;
            ans+=(((n>>0)&1)+'0');
            carry=((n>>1)&1);
            j++;

        }
        if(carry){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
        

        
    }
};