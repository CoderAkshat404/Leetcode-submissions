class Solution {
public:
    string temp="";
    vector<int> v;
    int n;
    void solve(char prev){
    if(temp.size()>10) return;
    if(!temp.empty() && stoll(temp)>1LL*n) return;

    for(char ch='0';ch<='9';ch++){
        if(ch>=prev){
            if(temp.empty() && ch=='0') continue; 

            temp+=ch;

            if(stoll(temp)<=1LL*INT_MAX)
                v.push_back(stoll(temp));

            solve(ch);
            temp.pop_back();
        }
    }
}
    int monotoneIncreasingDigits(int n) {
        this->n=n;
        char c='0';
        solve(c);
        v.push_back(0);
        sort(v.begin(),v.end());
        auto it=upper_bound(v.begin(),v.end(),n)-v.begin();
        it--;
        return v[it];
        
        
    }
};