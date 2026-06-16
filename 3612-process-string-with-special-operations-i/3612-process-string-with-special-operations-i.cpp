class Solution {
public:
    string processStr(string s) {
        bool rev = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '*') {
                if (ans.size() > 0) {
                    if (rev) {
                        string_view view(ans);
                        view.remove_prefix(1);
                        ans = string(view);
                    } else {
                        ans.pop_back();
                    }
                }
            } else if (c == '#') {
                ans += ans;
            } else if (c == '%') {
                rev = !rev;
            } else {
                if (rev) {
                    ans = c + ans;
                } else {
                    ans += c;
                }
            }
        }
        if (rev)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};