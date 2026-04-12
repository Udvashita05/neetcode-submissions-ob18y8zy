class MyCircularQueue {
    int f;
    int r;
    int *arr;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
        f = r =-1;
        arr = new int[size];  
    }
    
    bool enQueue(int value) {
        if((r+1)%size == f){
            return false;
        }
        else if(f == -1 and r == -1){
            f = r = 0;
        }
        else{
            r = (r+1)%size;
        }

        arr[r] = value;
        return true;
    }
    
    bool deQueue() {
        if(f==-1 and r==-1){
            return false;
        }
        else if (f == r){
            f = -1;
            r = -1;
            return true;
        }
        else{
            f=(f+1)%size;
        }
        return true;
    }
    
    int Front() {
        if(f == -1 and r == -1){
            return -1;
        }
        else{
            return arr[f];
        }
    }
    
    int Rear() {
        if(f == -1 and r == -1){
            return -1;
        }
        else{
            return arr[r];
        }
    }
    
    bool isEmpty() {
        if(f==-1 and r==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(f == (r+1)%size){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */