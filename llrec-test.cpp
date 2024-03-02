#include "llrec.h"
#include <fstream>
#include <functional>
#include <iostream>
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node *readList(const char *filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node *head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node *head);

Node *readList(const char *filename) {
    Node *h = NULL;
    ifstream ifile(filename);
    int v;
    if (!(ifile >> v))
        return h;
    h = new Node(v, NULL);
    Node *t = h;
    while (ifile >> v) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node *head) {
    Node *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct OddComp {
    bool operator()(int value) {
        if (value % 2 == 0) return false;
        return true;
    }
};

struct EveryComp {
    bool operator()(int value) {
        return true;
    }
};

struct NothingComp {
    bool operator()(int value) {
        return false;
    }
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node *head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    cout << "========llpivot==========\n";
    Node *smaller;
    Node *larger;
    llpivot(head, smaller, larger, 6);
    print(smaller);
    print(larger);

    head = readList(argv[1]);
    smaller = NULL;
    larger = NULL;
    llpivot(head, smaller, larger, 2);
    print(smaller);
    print(larger);

    head = readList(argv[1]);
    smaller = NULL;
    larger = NULL;
    llpivot(head, smaller, larger, 20);
    print(smaller);
    print(larger);

    head = NULL;
    smaller = NULL;
    larger = NULL;
    llpivot(head, smaller, larger, 20);
    print(smaller);
    print(larger);

    cout << "========llfilter==========\n";
    head = readList(argv[1]);
    Node *filtered = llfilter(head, OddComp());
    print(filtered);

    head = readList(argv[1]);
    filtered = llfilter(head, EveryComp());
    print(filtered);

    head = readList(argv[1]);
    filtered = llfilter(head, NothingComp());
    print(filtered);

    head = NULL;
    filtered = llfilter(head, EveryComp());
    print(filtered);

    return 0;
}
