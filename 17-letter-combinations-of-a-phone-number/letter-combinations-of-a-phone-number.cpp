class Solution {
public:
    vector<string>ans;
    void solve(string digits,unordered_map<char,string>&mp,string &temp,int idx){
        if(idx>=digits.length()){
            ans.push_back(temp);
            return;
        }
        char digit=digits[idx];
        string str=mp[digit];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(digits,mp,temp,idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";
        solve(digits,mp,temp,0);
        return ans;
    }
};