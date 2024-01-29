class MyQueue {
public:
    int elem=0;
    stack<int>st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.empty()){
            elem=x;
        }
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x=st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        return elem;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */