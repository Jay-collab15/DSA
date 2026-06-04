class Solution {
public:
    //Jay
    vector<string> ans;
    void solve(int idx, string num, long long target,
               long long value, long long prev,
               string expr) {
        if (idx == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }
        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0')
                break;
            string currStr = num.substr(idx, i - idx + 1);
            long long curr = stoll(currStr);
            if (idx == 0) {
                solve(i + 1, num, target,
                      curr, curr,
                      currStr);
            } else {
                solve(i + 1, num, target,
                      value + curr, curr,
                      expr + "+" + currStr);
                solve(i + 1, num, target,
                      value - curr, -curr,
                      expr + "-" + currStr);
                solve(i + 1, num, target,
                      value - prev + prev * curr,
                      prev * curr,
                      expr + "*" + currStr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(0, num, target, 0, 0, "");
        return ans;
    }
};