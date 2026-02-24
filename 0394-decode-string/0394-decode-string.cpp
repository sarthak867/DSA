class Solution {
public:
    string decodeString(string s) {
        stack<char> seq;

        for(char c : s){
            seq.push(c);

            if(c == ']'){
                string temp = "";
                string num = "";

                seq.pop();

                while(!seq.empty() && seq.top() != '['){
                    temp += seq.top();
                    seq.pop();
                }

                reverse(temp.begin(), temp.end()); // fix order

                seq.pop(); // remove '['

                while(!seq.empty() && isdigit(seq.top())){
                    num += seq.top();
                    seq.pop();
                }

                reverse(num.begin(), num.end()); 

                int n = stoi(num);

                string ans = "";
                while(n > 0){
                    ans += temp;
                    n--;  // important
                }

                for(char ch : ans){
                    seq.push(ch);
                }
            }
        }

        string res = "";
        while(!seq.empty()){
            res += seq.top();
            seq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};