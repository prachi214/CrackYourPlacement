class MyStack {
public:
queue<int>q;
    MyStack() {
       
    }
    
    void push(int x) {
         q.push(x);
        //  create stack behaviour
         for(int i =0;i<q.size()-1;i++){
        int front =    q.front();
        q.pop();
        q.push(front);
         }
    }
    
    int pop() {
       int top = q.front(); 
       q.pop();
       return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

