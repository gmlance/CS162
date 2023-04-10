#ifndef NODE_H
#define NODE_H


template <typename T>
class Node {
public:
    T val;
    Node<T>* next;

    Node<T>(T _val=T(), Node<T>* _next=nullptr) : val(_val), next(_next) {}
};


#endif // NODE_H
