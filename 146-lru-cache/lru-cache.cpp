class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* node) {
        Node* nextNode = head->next;

        node->next = nextNode;
        head->next = node;

        node->prev = head;
        nextNode->prev = node;
    }

    void delNode(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int limit;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* ansNode = mp[key];
        int ans = ansNode->val;

        mp.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            mp.erase(key);
            delNode(node);
        }

        if (limit == mp.size()) {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */