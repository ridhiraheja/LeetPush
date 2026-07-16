class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;

        for (string op : operations) {

            if (op == "C") {
                score.pop_back();
            }
            else if (op == "D") {
                score.push_back(2 * score.back());
            }
            else if (op == "+") {
                int n = score.size();
                score.push_back(score[n - 1] + score[n - 2]);
            }
            else {
                score.push_back(stoi(op));
            }
        }

        int sum = 0;
        for (int x : score)
            sum += x;

        return sum;
        
    }
};