class Solution {
public:
    string convertDateToBinary(string date) {
        string year=date.substr(0,4);
        int x=stoi(year);
        cout<<x<<endl;
        int l1=0;
        string ans="";
        while(x>>l1){
            l1++;
        }
        cout<<l1<<endl;
        string p="";
        for(int i=0;i<l1;i++){
            int a=(x>>i)&1;
            if(a){
                p+='1';
            }
            else{
                p+='0';
            }
        }
         reverse(p.begin(),p.end());
            ans+=p;
            ans+='-';
        string month=date.substr(5,2);
        x=stoi(month);
        l1=0;
        while(x>>l1){
            l1++;
        }
        p="";
        for(int i=0;i<l1;i++){
            int a=(x>>i)&1;
            if(a){
                p+='1';
            }
            else{
                p+='0';
            }
            
        }
        reverse(p.begin(),p.end());
            ans+=p;
            ans+='-';
        string day=date.substr(8,2);
        x=stoi(day);
        l1=0;
        while(x>>l1){
            l1++;
        }
        p="";
        for(int i=0;i<l1;i++){
            int a=(x>>i)&1;
            if(a){
                p+='1';
            }
            else{
                p+='0';
            }
            
        }
        reverse(p.begin(),p.end());
            ans+=p;
        return ans;


        
    }
};