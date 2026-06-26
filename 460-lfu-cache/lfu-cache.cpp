class Node {
public:
    int key, val, cnt;
    Node *next, *prev;

    Node(int k, int v) {
        key = k;
        val = v;
        cnt = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
public:
    int size;
    Node *head;
    Node *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);

        freqListMap[node->cnt]->removeNode(node);

        if (node->cnt == minFreq &&
            freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();

        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;

        nextHigherFreqList->addFront(node);

        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node* node = keyNode[key];
        int ans = node->val;

        updateFreqListMap(node);

        return ans;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];

            node->val = value;
            updateFreqListMap(node);

            return;
        }

        if (curSize == maxSizeCache) {
            List* list = freqListMap[minFreq];

            keyNode.erase(list->tail->prev->key);

            list->removeNode(list->tail->prev);

            curSize--;
        }

        curSize++;

        minFreq = 1;

        List* listFreq = new List();

        if (freqListMap.find(minFreq) != freqListMap.end()) {
            listFreq = freqListMap[minFreq];
        }

        Node* node = new Node(key, value);

        listFreq->addFront(node);

        keyNode[key] = node;
        freqListMap[minFreq] = listFreq;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */