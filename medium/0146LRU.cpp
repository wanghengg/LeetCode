//
// Created by wangheng on 2021/9/7.
//

#include <bits/stdc++.h>
using namespace std;

struct LinkedNode{
    int key, value;
    LinkedNode* pre;
    LinkedNode* next;
    LinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    LinkedNode(int key, int value) : key(key), value(value), pre(nullptr), next(nullptr) {}
};

class LRUCache{
private:
    LinkedNode* head;
    LinkedNode* tail;
    unordered_map<int, LinkedNode*> cache;
    int size;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new LinkedNode();
        tail = new LinkedNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        LinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            LinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            LinkedNode* node = new LinkedNode(key, value);
            addToHead(node);
            ++size;
            cache[key] = node;
            if (size > capacity) {
                LinkedNode* removed = removeTail();
                --size;
                cache.erase(removed->key);
                delete removed;
            }
        }
    }

    void removeNode(LinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void addToHead(LinkedNode* node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void moveToHead(LinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    LinkedNode* removeTail() {
        LinkedNode* node = tail->pre;
        removeNode(node);
        return node;
    }
};