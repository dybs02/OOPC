#ifndef _MAP_H_
#define _MAP_H_

#include "RedBlackTree.h"

template<class K, class V> class Map {


    class Pair {
        K key;
        V value;

        Pair(K key, V value)
        {
            this->key = key;
            this->value = value;
        }

        // friend ?
//        bool operator<(const Pair& l, const Pair& r)
        bool operator<(const Pair& r)
        {
            return key < r.key;
        }
    };

public:
    Map()
    {

    }

//    bool add(K key, V value)
    bool add(const K& key, const V& value)
    {
        return true;
    }

    V* find(const K& key) const
    {
        return nullptr;
    }

private:


};

#endif
