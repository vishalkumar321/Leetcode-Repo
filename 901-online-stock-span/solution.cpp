class StockSpanner {
public:

        stack<int> s;
        stack<int> spans;

    StockSpanner() {
        
    }
    
    int next(int price){
        
        int span = 1;
        
            while(s.size()>0 && s.top()<= price){
                span+= spans.top();
                s.pop();
                spans.pop();
            }
            s.push(price);
            spans.push(span);
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */