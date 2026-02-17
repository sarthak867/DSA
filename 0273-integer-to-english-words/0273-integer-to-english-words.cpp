class Solution {
public:
    string toword(int i) {
        string ans = "";
        
        if (i >= 100) {
            ans += toword(i / 100);
            ans += "Hundred ";
        }
        i %= 100;

        vector<string> words = {
            "", "One ", "Two ", "Three ", "Four ",
            "Five ", "Six ", "Seven ", "Eight ", "Nine ",
            "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
            "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
        };

        if (i > 0 && i <= 19)
            ans += words[i];
        else {
            vector<string> tens = {
                "", "", "Twenty ", "Thirty ", "Forty ",
                "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "
            };

            if (i >= 20) {
                ans += tens[i / 10];
                ans += words[i % 10];
            }
        }

        return ans;
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";

        vector<string> scale = {"", "Thousand ", "Million ", "Billion "};
        string ans = "";
        int idx = 0;

        while(num > 0){
            int part = num % 1000;   

            if(part != 0){
                ans = toword(part) + scale[idx] + ans;
            }

            num /= 1000;
            idx++;
        }

        if(ans.back() == ' ') ans.pop_back();

        return ans;
    }
};
