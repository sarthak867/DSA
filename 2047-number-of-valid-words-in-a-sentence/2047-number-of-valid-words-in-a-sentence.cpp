class Solution {
public:
    int countValidWords(string sentence) {
        int t = 0;
        bool vt = true;    
        bool p = false;     
        bool h = false;     
        string s = "";

        sentence += ' ';  

        for (int i = 0; i < sentence.size(); i++) {
            char c = sentence[i];

            if (c == ' ') {
                if (!s.empty() && vt && s.back() != '-') {
                    t++;
                }
                vt = true;
                p = false;
                h = false;
                s = "";
                continue;
            }

            if (!vt) continue;

            if (isdigit(c)) {
                vt = false;
            }
            else if (islower(c)) {
                if (p) vt = false;
                else s += c;
            }
            else if (c == '-') {
                if (h || p || s.empty() ||
                    !islower(s.back()) || 
                    i+1 >= sentence.size() ||
                    !islower(sentence[i+1])) {
                    vt = false;
                } else {
                    h = true;
                }
                s += c;
            }
            else if (c == '!' || c == '.' || c == ',') {
                if (p) vt = false;
                else p = true;
                s += c;
            }
            else {
                vt = false;
            }
        }

        return t;
    }
};