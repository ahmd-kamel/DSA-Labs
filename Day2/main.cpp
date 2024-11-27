#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
    Queue q(5);

    q.displayQueue();
    for (int i = 0; i < 6; i++)
    {
        q.enqueue(i) ? cout << i << " Enqueued successfully\n" : cout << "Failed to enqueue " << i << endl; 
    }
    q.displayQueue();

    int data;
    q.dequeue(data);
    cout << "data : " << data << endl;
    q.displayQueue();
    q.dequeue(data);
    cout << "data : " << data << endl;
    q.displayQueue();

    q.dequeue(data);    
    q.dequeue(data);   
    q.displayQueue();
    q.dequeue(data) == 1 ? cout << "sucssess\n" : cout << "failed\n";
    q.dequeue(data) == 1 ? cout << "sucssess\n" : cout << "failed\n";
    q.displayQueue();

    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    int topValue = 0;
    (stack.peek(topValue)) ? cout << "Top :" <<  topValue << endl : cout << "Failed\n";
    stack.pop();
    (stack.peek(topValue)) ? cout << "Top :" <<  topValue << endl : cout << "Failed\n";
    stack.pop();
    (stack.peek(topValue)) ? cout << "Top :" <<  topValue << endl : cout << "Failed\n";
    stack.pop();
    (stack.peek(topValue)) ? cout << "Top :" <<  topValue << endl : cout << "Failed\n";
    return 0;
}
