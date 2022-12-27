#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>
#include "LinkedList.h"

template<class K, class V> class Map {
    class Pair {
    public:
        K key;
        V value;

        Pair() {}

        Pair(K key)
        {
            this->key = key;
        }

        Pair(K key, V value)
        {
            this->key = key;
            this->value = value;
        }

        bool operator==(const Pair& r) const
        {
            return key == r.key;
        }

        friend std::ostream& operator<<(std::ostream& s, const Pair& pair)
        {
            s << "[" << pair.key << ": " << pair.value << "]";
            return s;
        }
    };

    LinkedList<Pair> list;

public:
    Map()
    {

    }

    Map(const Map<K, V>& map)
    {
        list = LinkedList(map.list);
    }

    bool add(K key, V value)
    {
        Pair newPair(key, value);

        if (list.contains(newPair)) {
            return false;
        }

        list.add(newPair);
        return true;
    }

    bool remove(K key)
    {
        return list.remove(Pair(key));
    }

    V* find(K key)
    {
        Pair* found = list.getPtr(Pair(key));

        if (found == nullptr) {
            return nullptr;
        }

        return &(found->value);
    }

    Map& operator=(const Map& map)
    {
        list = LinkedList(map.list);
        return *this;
    }

private:
    friend std::ostream& operator<<(std::ostream& s, const Map& map)
    {
        return s << map.list;
    }

};

#endif