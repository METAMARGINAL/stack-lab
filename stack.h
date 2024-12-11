#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T& peek() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

void find_bracket_pairs(const string& text) {
    Stack<int> stack;
    pair<int, int> pairs[1000]; 
    int pair_count = 0; 

   
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == '(') {
            
            stack.push(i);
        }
        else if (text[i] == ')') {
            
            int opening_index = stack.peek();
            stack.pop();
            pairs[pair_count++] = { opening_index + 1, i + 1 }; 
        }
    }

    sort(pairs, pairs + pair_count);


    for (int i = 0; i < pair_count; ++i) {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }
}