class Solution {
public:
    int bestClosingTime(string customers) {
        unordered_map<char, int> freq;
        for(char c : customers){
            freq[c]++;
        }
        int pan = freq['Y'];
        int time = 0;
        for(int i =0 ; i<customers.size(); i++){
            if(customers[i]=='Y') freq['Y']--;
            else freq['Y']++;
            if(freq['Y']<pan){
                pan = freq['Y'];
                time = i+1;
            }
        }
        return time;
    }
};