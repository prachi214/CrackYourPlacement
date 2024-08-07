class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;

    StockSpanner(){
        // each day starts with fresh data like price
        ind = -1;
        while (!st.empty()) {
            st.pop();
        }
    }
    
    int next(int price) {
        ind = ind + 1;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        // PGE
        int ans = st.empty() ? ind+1 : ind - st.top().second;
        st.push({price, ind});
        return ans;
    }
};