
class Solution {
public:
vector<int>digits;
string curr="";
set<int> ans;
map<int,int> taken;
void solve(int i){
    if(i>=digits.size()){
        if(!curr.empty()){
            long long x=stoll(curr);
            int len=0;
            long long temp=x;;
            while(temp>0){
                len++;
                temp=temp/10;
            }
            if(x%2==0 && len==3){
                ans.insert(x);
            }
        }
        return;  
    }
    if(taken[i]==0 && curr.length()<3){
        curr+=to_string(digits[i]);
        taken[i]=1;
        solve(0);
        curr.pop_back();
        taken[i]=0;

    }
    solve(i+1);
}
    int totalNumbers(vector<int>& digits) {
        this->digits=digits;
        solve(0);
        return ans.size();

        
    }
};