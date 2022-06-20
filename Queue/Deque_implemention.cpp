class Deque
{
    int* arr;
    int front, rear, size;
    
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check whther queue is full or not
        if(isFull())
        {
            return false;
        }
        // first element
        else if(isEmpty()){
            front = rear = 0;
        }
        //cyclic order
        else if(front == 0 && rear != size - 1){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull())
        {
            return false;
        }
        // first element
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){ // to maintain cyclic order
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
        
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){ // to check queue is empty
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1; // ab ya exit ni karega front
        if(front == rear){ // single element is present
            front = rear = -1;
        }
        else if(front == size-1){ // to maintain cyclic nature
            front = 0;
        }
        else // formal flow
            front++;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
         if(isEmpty()){ // to check queue is empty
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1; // ab ya exit ni karega front
        if(front == rear){ // single element is present
            front = rear = -1;
        }
        else if(rear == 0){ // to maintain cyclic nature
            rear = size - 1;
        }
        else // formal flow
            rear--;
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1)
            return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if(front == 0 && rear == size-1 || (front!= 0 && rear == (front-1)%(size-1)))
        {
            return true;
        }
        else
            return false;
    }
};