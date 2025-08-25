#include <iostream>
using namespace std;

template <class T>
class Stack {
    T* arr;
    int top;
    int cap;
public:
    Stack(int c) {
        cap = c;
        arr = new T[c];
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == cap - 1;
    }
    void push(T v) {
        if (isFull()) {
            cout << "Stack Full\n";
            return;
        }
        arr[++top] = v;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return;
        }
        top--;
    }
    T topEl() {
        if (isEmpty()) {
            cout << "No element\n";
            return T();
        }
        return arr[top];
    }
    void show() {
        if (isEmpty()) { cout << "Stack Empty\n"; return; }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack<int> st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.show();

    cout << "Top: " << st.topEl() << endl;

    st.pop();
    st.show();

    cout << (st.isEmpty() ? "Empty\n" : "Not Empty\n");
    cout << (st.isFull() ? "Full\n" : "Not Full\n");

    return 0;
}
