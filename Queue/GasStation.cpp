class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0; // this variable denotes deficiency of petrol for
                         // reaching till next gas station
        int balance = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            balance = balance + gas[i] - cost[i];
            if (balance < 0) {
                deficit += abs(balance);
                // if with gas[i] ,gas is not enough for reaching next gas
                // station then without this station can't reach destination,
                // for avoiding duplicate comparision
                start = i + 1;
                balance = 0;
            }
        }
        if (balance - deficit >= 0)
            // complete circuit
            return start;
        else
            return -1;
    }
};