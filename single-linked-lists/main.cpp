/**
 * For some reason, on MacOS it's not working when we split classes into separate files.
 * That's why all the implementation is part of main.cpp file.
 *
 * This is far from ideal, but for learning purposes it's ok.
 *
 * Author: Nemanja Tanaskovic
 * E-Mail: nemanjatanaskovic@elfak.rs
 */

#include <iostream>

template <class T>
class SLLNode {
public:
    T info;
    SLLNode<T>* next; // pointer to next node.
public:
    // Constructor
    SLLNode() {
        next = nullptr;
    };

    SLLNode(T i) {
        info = i;
        next = nullptr;
    };

    SLLNode(T i, SLLNode<T>* n) {
        info = i;
        next = n;
    };

    // Destructor empty.
    // TODO: Please find out why it's empty?
    ~SLLNode() {

    };

    T getNodeInfo() {
        return info;
    }

    SLLNode<T>* getNextNode() {
        return next;
    }

    bool isEqual(T el) {
        return el == info;
    };
};

template <class T>
class SLList {
protected:
    SLLNode<T> *head, *tail;
public:
    // Constructor
    SLList() {
        head = tail = nullptr;
    };

    // Destructor
    ~SLList() {

    };

    // Interesting (best) approach for checking if the list is empty.
    // If head is NULL, then return false, otherwise return true.
    bool isListEmpty() {
        return head == nullptr;
    }

    // We are inserting only value T on beginning of the list - NOT THE WHOLE NODE!!!
    void addToHead(T el) {
        // If the list is empty, then this head param we are passing to node will be NULL.
        head = new SLLNode<T>(el, head);

        // If tail is null, then it means that list has only one element (head).
        // In that case make sure that you assign same value to tail as well.
        if (tail == nullptr) {
            tail = head;
        }
    };

    // Like with addToHead, in addToTail we are passing T element (instead of complete NODE).
    void addToTail(T el) {
        if (head == nullptr) {
            addToHead(el);
        } else {
            tail->next = new SLLNode<T>(el);
            tail = tail->next;
        }
    };

    T deleteFromHead() {
        T el = head->info;
        // If the head is equal to tail, then make sure you delete both head and tail.
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        return el;
    };

    T deleteFromTail() {
        T el = tail->info;
        // SLLNode<T>* tmp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            SLLNode<T>* tmp;
            for (tmp = head; tmp->next != tail; tmp = tmp->next);
            tail = tmp;
            tail->next = nullptr;
            delete tmp;
        }
        return el;
    };

    bool isInList(T el) {
        SLLNode<T>* tmp;

        for(tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->info == el) {
                return true;
            }
        }

        return false;
    };

    SLLNode<T>* findNodePtr(T el) {
        SLLNode<T>* tmp;
        for (tmp = head; tmp != nullptr && !(tmp->isEqual(el)); tmp = tmp->next) {
            // Element found, return it.
            return tmp;
        }

        return nullptr;
    };
};

int main() {
    SLLNode<int> secondTestingNode(2);
    SLLNode<int> firstTestingNode(1, &secondTestingNode);

    SLList<int> firstTestingList;
    firstTestingList.addToHead(2);
    firstTestingList.addToHead(1);
    firstTestingList.addToTail(3);
//    firstTestingList.deleteFromHead();
//    firstTestingList.deleteFromTail();
    firstTestingList.isInList(2);
    firstTestingList.findNodePtr(2);

    std::cout << "First Testing Node (info value): " << firstTestingNode.getNodeInfo() << std::endl;
    std::cout << "getNextNode() method on firstTestingNode (info value): " << firstTestingNode.getNextNode()->getNodeInfo() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
