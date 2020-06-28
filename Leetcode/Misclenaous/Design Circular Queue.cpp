/*  Circular queue is used to avoid the wastage of space in a regular queue implementation using arrays

    Idea is to maintain 2 pointers, rear & front which will initially point to -1 and when we've to perform enqueue operation we increment the rear circularly i.e if we're at the end
    then we'll move to beginnning. PS: when we're inserting the first element we should also update our front to point 0, along with incrementing rear.

    So condition for empty = (front==0 && rear==size-1) || (front == rear+1)
    The first case occurs when we keep on enqueing the elements without dequeing and reach the end of queue, whereas the second case will occur when we perform some delete operations as well and
    our rear pointer reaches the end and from their move to beginning and again we keep on adding elements such that it reaches just at the back of front and hence our queue get's full

    Example:    size = 5
    enq(1)
    enq(2)
    enq(3)
    enq(4)
    enq(5)
    deq()
    deq()
    enq(6)
    enq(7)  :> queue get's full

*/

class MyCircularQueue {

private:
    int rear;
    int front;
    int size;
    vector<int> v;

public:
    MyCircularQueue(int k) {
        rear = front = -1;
        size = k;
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(front==-1)       // if our queue is empty() so far, and we're going to add first element to our queue. Then along with 
            front=0;
        rear = (rear+1)%size;
        v[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front==rear)         // when we've just one element in queue, they could be equal to 0 or some other no. as well
            front = rear = -1;
        else
            front = (front+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return (front==-1);
    }
    
    bool isFull() {
        return ((front==0 && rear == size-1) || (front == rear+1));
    }
};
