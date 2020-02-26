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
class DLLNode {
public:
    T info;
    DLLNode<T> *prev, *next;

    DLLNode() {
        prev = next = nullptr;
    };

    ~DLLNode() {

    };

    DLLNode(T el) {
        info = el;
        prev = next = nullptr;
    };

    DLLNode(T el, DLLNode<T>* p, DLLNode<T>* n) {
        info = el;
        prev = p;
        next = n;
    };

    T print() {
        return info;
    };

    bool isEqual(T el) {
        return info == el;
    };
};

template <class T>
class DLList {
protected:
    DLLNode<T> *head, *tail;
public:
    DLList() {
        head = tail = nullptr;
    };

    ~DLList() {

    };

    bool isEmpty() {
        return head == nullptr;
    };

    bool isInList(T el) {
        for(DLLNode<T> *tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->isEqual(el)) {
                return true;
            }
        }

        return false;
    };

    void addToHead(T el) {
        if (isEmpty()) {
            // Head does not exist ---> insert it as first element.
            head = tail = new DLLNode<T>(el);
        } else {
            head = new DLLNode<T>(el, nullptr, head);
            head->next->prev = head;
        }
    }

    void addToTail(T el) {
        if (isEmpty()) {
            head = tail = new DLLNode<T>(el);
        } else {
            tail = new DLLNode<T>(el, tail, nullptr);
            tail->prev->next = tail;
        }
    };

    DLLNode<T>* findNodePtr(T el) {
        // Find Node based on provided info.
        if (!isEmpty()) {
            if (head->isEqual(el)) {
                return head;
            } else if (tail->isEqual(el)) {
                return tail;
            } else {
                // Since the element is not located on head or tail, we need to find it inside the list (if it exists).
                for(DLLNode<T>* pom = head->next; pom != tail; pom = pom->next) {
                    if (pom->isEqual(el)) {
                        return pom;
                    }
                }
            }
        }

        return nullptr;
        // throw "Element not found";
    };

    DLLNode<T>* getHead() {
        if (!isEmpty()) {
            return head;
        }

        return nullptr;

        // throw "List is empty!";
    };

    DLLNode<T>* getNext(DLLNode<T>* ptr) {
        if (ptr->next != nullptr) {
            return ptr->next;
        }

        return nullptr;

        // throw "This element doesn't have next Node reference";
    };

    T getHeadEl() {
        if (head != nullptr) {
            return head->info;
        }

        return -1;
    };

    T getNextEl(T el) {
        DLLNode<T>* tmp = findNodePtr(el);
        if (tmp->next != nullptr) {
            return tmp->next->info;
        }

        return -1;
    };

    void deleteFromHead() {
        if ((head == tail) && !isEmpty()) {
            head = tail = nullptr;
        } else if (head != nullptr) {
            head->next->prev = nullptr;
            head = head->next;
        }
    };

    void deleteFromTail() {
        if ((head == tail) && !isEmpty()) {
            head = tail = nullptr;
        } else if (tail != nullptr) {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
    };

    void deleteEl(T el) {
        // First make sure we have this element.
        if (!isEmpty()) {
            if (head->isEqual(el)) {
                deleteFromHead();
            } else if (tail->isEqual(el)) {
                deleteFromTail();
            } else {
                for (DLLNode<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
                    if (tmp->isEqual(el)) {
                        // Element found, remove it.
                        tmp->prev->next = tmp->next;
                        tmp->next->prev = tmp->prev;
                    }
                }
            }
        }
    };

    void printAll() {
        if (!isEmpty()) {
            for(DLLNode<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
                std::cout << tmp->info << std::endl;
            }
        }
    };
};

int main() {
    DLList<int> DLList;
    DLList.addToHead(4);
    DLList.addToHead(3);
    DLList.addToHead(2);
    DLList.addToHead(1);
    DLList.addToTail(5);
    DLList.addToTail(6);

    if (DLList.isInList(3)) {
        std::cout << "3 is in List!" << std::endl;
    }

    if (!DLList.isInList(10)) {
        std::cout << "10 is NOT in the List!" << std::endl;
    }

    DLList.findNodePtr(1); // Find Node that is located in head.
    DLList.findNodePtr(6); // Find Node that is located in tail.
    DLList.findNodePtr(4); // Find random Node.
    DLList.findNodePtr(23); // Try to find not existing Node.

    DLList.getHead();
    DLList.getNext(DLList.findNodePtr(3));

    std::cout << "getHeadEl method returned: " << DLList.getHeadEl() << std::endl;
    std::cout << "getNextEl(2) method returned: " << DLList.getNextEl(2) << std::endl;

    std::cout << "List BEFORE deleting Node 3" << std::endl;
    DLList.printAll();

    DLList.deleteEl(3);
    std::cout << "List after deleting Node 3" << std::endl;
    DLList.printAll();

    DLList.deleteEl(1);
    std::cout << "List after deleting Node 1 - Head Node" << std::endl;
    DLList.printAll();

    DLList.deleteEl(6);
    std::cout << "List after deleting Node 6 - Tail Node" << std::endl;
    DLList.printAll();
    return 0;
}
