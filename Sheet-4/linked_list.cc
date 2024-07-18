#include "linked_list.hh"
#include <iostream>

void Node::setNextItem(Node* n)
{
    next_item = &*n;
}

Node* Node::getNextItem()
{
    return next_item;
}

Node* Node::getNextItem() const
{
    return next_item;
} 

Node* List::first() const
{
    if (!first_item)
    {
        std::cerr << "Tried to access first element of empty list";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return first_item;
}

Node* List::next(const Node* n) const
{
    //Node* m = n->getNextItem();

    return n->getNextItem();
}

void List::append(int i)
{
    if (first_item!=0)
    {
        Node* n = first();
        while (n->getNextItem() != 0)
        {
            n = n->getNextItem();
        }
        Node* m = new Node{i};
        n->setNextItem(m);
    }
    else
    {
        first_item = new Node(i);
    }
    max_valid = false;
}

void List::insert(Node* n, int i)
{
    Node* m = new Node(i, n);
    if (n!=first())
    {
        //m->next_item = n;
        Node* p = first();
        while (p->getNextItem()!=n)
        {
            p = p->getNextItem();
        }
        p->setNextItem(m);
    }
    else
    {
        first_item = m;
    }
    max_valid = false;
}

void List::erase(Node* n)
{
    if (n==first())
    {
        first_item = n->getNextItem();
        delete n;
        n = nullptr;
    }
    else
    {
        Node* m = first_item;
        while (m->getNextItem()!=n)
        {
            m = m->getNextItem();
        }
        m->setNextItem(n->getNextItem());
        delete n;
        n = nullptr;
    }
    max_valid = false;
}

int List::len() const
{
    int i{0};
    for (Node *n = first(); n != 0; n = next(n))
    {
        ++i;
    }
    return i;
}

int List::max() const
{
    if (max_valid)
    {
        return max_value;
    }
    else
    {
        Node* n = first();
        max_value = n->value;
        while (n != 0)
        {
            if (n->value > max_value)
            {
                max_value = n->value;
            }
            n = n->getNextItem();
        }
        max_valid = true;
        return max_value;
    }
}

List::~List()
{
    // Node* n = first_item;
    while (first_item)
    {
        erase(first_item);
    }
}
