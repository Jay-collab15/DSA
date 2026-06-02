class Solution {
public:
    // Jay
    vector<string> ans;
    vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int idx, string& digits, string curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for (char ch : letters) {
            solve(idx + 1, digits, curr + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        solve(0, digits, "");
        return ans;
    }
};