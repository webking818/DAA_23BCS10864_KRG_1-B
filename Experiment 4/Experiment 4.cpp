#include <iostream>
using namespace std;

class Node {
public:
    int d;
    Node* p;
    Node* n;
    Node(int v) {
        d = v;
        p = NULL;
        n = NULL;
    }
};

class DLL {
    Node* h;
public:
    DLL() { h = NULL; }
    void ib(int v) {
        Node* x = new Node(v);
        if (!h) { h = x; return; }
        x->n = h;
        h->p = x;
        h = x;
    }
    void ie(int v) {
        Node* x = new Node(v);
        if (!h) { h = x; return; }
        Node* t = h;
        while (t->n) t = t->n;
        t->n = x;
        x->p = t;
    }
    void db() {
        if (!h) return;
        Node* t = h;
        h = h->n;
        if (h) h->p = NULL;
        delete t;
    }
    void de() {
        if (!h) return;
        Node* t = h;
        while (t->n) t = t->n;
        if (t->p) t->p->n = NULL;
        else h = NULL;
        delete t;
    }
    void sh() {
        Node* t = h;
        cout << "DLL: ";
        while (t) {
            cout << t->d << " ";
            t = t->n;
        }
        cout << endl;
    }
};

class CLL {
    Node* h;
public:
    CLL() { h = NULL; }
    void ib(int v) {
        Node* x = new Node(v);
        if (!h) { h = x; h->n = h; return; }
        Node* t = h;
        while (t->n != h) t = t->n;
        t->n = x;
        x->n = h;
        h = x;
    }
    void ie(int v) {
        Node* x = new Node(v);
        if (!h) { h = x; h->n = h; return; }
        Node* t = h;
        while (t->n != h) t = t->n;
        t->n = x;
        x->n = h;
    }
    void db() {
        if (!h) return;
        Node* t = h;
        if (h->n == h) { delete h; h = NULL; return; }
        Node* l = h;
        while (l->n != h) l = l->n;
        h = h->n;
        l->n = h;
        delete t;
    }
    void de() {
        if (!h) return;
        if (h->n == h) { delete h; h = NULL; return; }
        Node* t = h;
        while (t->n->n != h) t = t->n;
        Node* y = t->n;
        t->n = h;
        delete y;
    }
    void sh() {
        if (!h) { cout << "CLL: empty\n"; return; }
        Node* t = h;
        cout << "CLL: ";
        do {
            cout << t->d << " ";
            t = t->n;
        } while (t != h);
        cout << endl;
    }
};

int main() {
    DLL a;
    a.ib(10);
    a.ie(20);
    a.ib(5);
    a.sh();
    a.db();
    a.de();
    a.sh();

    CLL b;
    b.ib(10);
    b.ie(20);
    b.ib(5);
    b.sh();
    b.db();
    b.de();
    b.sh();

    return 0;
}
