#ifndef _REDBLACKTREE_H_
#define _REDBLACKTREE_H_

#define COLOR int
#define RED 0
#define BLACK 1

template<class K> class RedBlackTree {
public:
    RedBlackTree()
    {

    }

    void insert(K key)
    {

    }

    bool delete(K key)
    {

    }

    K search(K key)
    {

    }

private:
    class Node {
        COLOR color;
        K key;
        Node* left;
        Node* right;
        Node* parent;

        Node()
        {

        }
    };

};


#endif