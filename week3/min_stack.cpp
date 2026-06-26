class MinStack {
public:
    stack<int> s;
    stack<int> mini;
    MinStack() {
        
    }
    
    void push(int value) {
      if(s.empty()){
      s.push(value);
      mini.push(value);
      }
      else{
        if(value <= mini.top()){
            mini.push(value);
        }
        s.push(value);
      }
      return;
       
    }
    
    void pop() {
        if(s.top() == mini.top()){
            s.pop();
            mini.pop();
        }
        else{
            s.pop();
        }
    }
    
    int top() {
        return(s.top());
    }
    
    int getMin() {
      return mini.top();  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */