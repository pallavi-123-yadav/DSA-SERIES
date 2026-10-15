class StockSpanner {
public:
int day =0;
        stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span;
        while(!st.empty() && st.top().first<=price) {
            st.pop();

        }
        
        if(st.empty()) {
            span=day+1;

        }
        else {
            span=day-st.top().second;
        }
        st.push({price,day});
        day++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */