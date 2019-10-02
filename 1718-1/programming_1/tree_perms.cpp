#include <iostream>
#include <cassert>
using namespace std;

struct node {
    int value;
    node* next;
    node* next_stack_node;
};

// stores the final permutation
node* stack = nullptr;

void process();
void push_stack(node* element);
node* pop_stack();
void nest(node* remaining);

int main()
{
    // expected 1 < n
    int n;
    cout << "n: "; cin >> n;
    if(n < 2) { cout << "invalid n\n"; return -1; }

    // create nodes from back to front so that struct shorthand initialization can be used
    node* current = nullptr;
    for(int i = n-1; i >= 0; i--) {
        current = new node({i, current});
    }
    node* zeronode = current;

    // check nodes are fine
    for(int i = 0; i < n; current = current->next) 
        assert(current->value == i++);

    // start reccursion
    nest(zeronode);
    return 1;
}

void nest(node* remaining) {
    // everything should be in the stack now
    if(remaining == nullptr)
    {
        process();
        return;
    }

    // only one node left
    if(remaining->next == nullptr){ 
        push_stack(remaining);
        nest(nullptr);
        pop_stack();
        return;
    }

    // easier to omit the first element this way
    push_stack(remaining);
    nest(remaining->next);
    pop_stack();

    // inner nodes
    node *tmp, *prev = remaining;
    while(prev->next != nullptr) {
        push_stack(prev->next);
        prev->next = prev->next->next;
        nest(remaining);
        prev->next = pop_stack();
        prev = prev->next; 
    }
    return;

}

void process() {
    node* prev = stack;
    while(prev != nullptr) {
        cout << prev->value << " ";
        prev = prev->next_stack_node; 
    }
    cout << "\n";
}

node* pop_stack() {
    node* tmp = stack;
    stack = stack->next_stack_node;
    return tmp;
}

void push_stack(node* element) {
    element->next_stack_node = stack;
    stack = element;
}