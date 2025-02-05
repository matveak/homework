#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head; 
    Node* tail; 
public:
    Queue() : head(nullptr), tail(nullptr) {} 

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node* newNode = new Node{ value, nullptr }; 

        if (isEmpty()) { 
            head = newNode; 
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;     
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Error: ochered pusta." << std::endl;
            return;
        }

        Node* temp = head;  
        head = head->next; 

        if (head == nullptr) { 
            tail = nullptr;  
        }

        delete temp; 
    }


    T peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Cannot peek at an empty queue." << std::endl;
            return T{}; 
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    Queue<int> myQueue;

    std::cout << "Is empty: " << myQueue.isEmpty() << std::endl;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    std::cout << "Is empty: " << myQueue.isEmpty() << std::endl;
    std::cout << "Peek: " << myQueue.peek() << std::endl;   

    myQueue.pop();
    std::cout << "Peek after pop: " << myQueue.peek() << std::endl; 

    myQueue.pop();
    myQueue.pop();

    std::cout << "Is empty: " << myQueue.isEmpty() << std::endl; 

    myQueue.pop();

    return 0;
}