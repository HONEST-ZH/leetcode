class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        min_hp.push(val);
    }
    
    void pop() {
        int temp = stack.top();
        stack.pop();
        //min_hp.pop();不能直接pop,和stack弹出的不是一个东西！
        hp_lazy_del(temp);//懒删除对应元素   
        hp_checktop();    
        }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {    
        hp_checktop(); 
        return  min_hp.top();    
   
    }
private:
    //使用最小堆辅助栈记录最小值
    stack<int> stack; 
    priority_queue<int,vector<int> ,greater<int>> min_hp;    
    //使用哈希表辅助记录被删除过的值，会重复，用unordered_mutiset
    unordered_multiset<int> hash_table;    
    //最小堆的懒删除，需要删除时使用一个辅助的哈希表记录被删除的值，在访问最小堆堆顶时检查是否在删除表中。
    void hp_lazy_del(int val){
       hash_table.insert(val);
    }
    //如果堆顶元素在哈希表中，pop堆顶元素，删除表中对应项
    void hp_checktop(){   
        while(hash_table.find(min_hp.top()) != hash_table.end()){
          int temp = min_hp.top();
          min_hp.pop();
          hash_table.erase(hash_table.find(temp));
       }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */