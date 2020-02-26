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

    T print() {
        return info;
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

    void printAll() {
        for (SLLNode<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
            std::cout << tmp->print() << std::endl;
        }
    }

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
            if (tmp->isEqual(el)) {
                return true;
            }
        }

        return false;
    };

    SLLNode<T>* findNodePtr(T el) {
        SLLNode<T>* tmp;
        for (tmp = head; tmp != nullptr; tmp = tmp->next) {
            // Element found, return it.
            if (tmp->isEqual(el)) {
                return tmp;
            }
        }

        return nullptr;
    };

    SLLNode<T>* getNext(SLLNode<T>* ptr) {
        if(ptr) {
            return ptr->next;
        } else {
            return nullptr;
        }
    };

    T getHeadEl() {
        if (head) {
            return head->info;
        } else {
            throw "The list is empty!";
        }
    };

    T getNextEl(T el) {
        // First we need to find this Node in our List.
        SLLNode<T>* pom = findNodePtr(el);

        if (pom->next == nullptr) {
            throw "This element doesn't have next element!";
        } else {
            return (pom->next)->info;
        }
    };

    void deleteEl(T el) {
        if (!isListEmpty()) {
            // Case 1: We have only one element in our list.
            if ((head == tail) && head->isEqual(el)) {
                head = tail = nullptr;
            } else if (head->info == el) {
                // Remove from head
                deleteFromHead();
            } else if (tail->info == el) {
                deleteFromTail();
            } else {
                SLLNode<T> *pred, *tmp;
                for(pred = head, tmp = head->next; tmp != nullptr; pred = pred->next, tmp = tmp->next) {
                    if (tmp->isEqual(el)) {
                        pred->next = tmp->next;
                    }
                }

            }
        }
    };
};

int main() {
    SLLNode<int> secondTestingNode(2);
    SLLNode<int> firstTestingNode(1, &secondTestingNode);

    SLList<int> firstTestingList;
    SLList<int> emptyList;
    firstTestingList.addToHead(2);
    firstTestingList.addToHead(1);
    firstTestingList.addToTail(3);
//    firstTestingList.deleteFromHead();
//    firstTestingList.deleteFromTail();
    firstTestingList.isInList(2);
    SLLNode<int>* findNode = firstTestingList.findNodePtr(2);
    firstTestingList.getHeadEl();
    firstTestingList.getNextEl(2);

    firstTestingList.deleteEl(2);
    firstTestingList.printAll();

    std::cout << "First Testing Node (info value): " << firstTestingNode.getNodeInfo() << std::endl;
    std::cout << "getNextNode() method on firstTestingNode (info value): " << firstTestingNode.getNextNode()->getNodeInfo() << std::endl;
    std::cout << "findNodePtr(2) method returned: " << findNode->info << std::endl;
    std::cout << "firstTestingList.getNext(findNode)->info : It should return 3 since findNode is equal to 2. Result: " << firstTestingList.getNext(findNode)->info << std::endl;
    return 0;
}
