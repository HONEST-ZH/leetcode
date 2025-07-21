class MyQueue {
public:
    MyQueue() {    
          }
    void push(int x) {
        //入队时，将输出堆栈中的所有元素放入输入堆栈，实现在队尾添加元素
        output2input();
        input_stack.push_front(x);
        this->size++; 
    }    
    int pop() {
        //空判断，根据题意可以不用
        input2output();
        int res = output_stack.front();
        output_stack.pop_front();
        this->size--;
        return res;
    }
    
    int peek() {
        int res;
        input2output();
        res = output_stack.front();
        return res;
    }
    
    bool empty() {
        if (this->size == 0) return true;
        else return false;
    }
private:
    //使用输入堆栈和输出堆栈模拟队列的入队和出队
    deque<int> input_stack; 
    deque<int> output_stack;
    int size = 0;  

    void input2output(){
        int temp;
        while (!input_stack.empty()){
            temp = input_stack.front();
            input_stack.pop_front();
            output_stack.push_front(temp);
       }
    }
    void output2input(){
        int temp;
        while (!output_stack.empty()){
            temp = output_stack.front();
            output_stack.pop_front();
            input_stack.push_front(temp);
       }
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