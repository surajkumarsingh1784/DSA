class Solution {
public:
    vector<string> ans;

    void solve(string s, int idx, int part, string curr){
        if(part == 4 && idx == s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if(part >= 4) return;

        for(int len = 1; len <= 3 && idx + len <= s.size(); len++){
            string temp = s.substr(idx, len);

            if((temp[0] == '0' && temp.size() > 1) || stoi(temp) > 255)
                continue;

            solve(s, idx + len, part + 1, curr + temp + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};