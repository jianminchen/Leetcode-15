class Queue {
public:
    // Push element x to the back of queue.
    stack<int> s1, s2;
    void move(){
        while(s1.empty() == false){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.empty()){
            move();
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(s2.empty()){
            move();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};
