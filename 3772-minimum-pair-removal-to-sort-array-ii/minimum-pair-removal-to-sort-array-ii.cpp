typedef long long ll;

const int MAX_N = 100005;

struct Node {
    ll v;
    int id;
};

using It = std::list<Node>::iterator;

struct Item {
    It a;
    It b;
    ll sum;
    int ida;
    int idb;

    Item() {}
    Item(It x, It y) : a(x), b(y), sum(x->v + y->v), ida(x->id), idb(y->id) {}
};

struct Cmp {
    bool operator()(const Item& x, const Item& y) const {
        if (x.sum != y.sum)
            return x.sum > y.sum;
        return x.ida > y.ida;
    }
};

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 1)
            return 0;

        std::list<Node> lst;
        std::bitset<MAX_N> removed;
        std::priority_queue<Item, std::vector<Item>, Cmp> pq;

        int bad = 0;
        int ops = 0;

        lst.push_back({(ll)nums[0], 0});

        for (int i = 1; i < n; i++) {
            lst.push_back({(ll)nums[i], i});
            auto b = std::prev(lst.end());
            auto a = std::prev(b);

            pq.push(Item(a, b));
            if (nums[i - 1] > nums[i])
                bad++;
        }

        while (bad > 0 && !pq.empty()) {
            Item cur = pq.top();
            pq.pop();

            if (removed[cur.ida] || removed[cur.idb])
                continue;
            if (cur.a == lst.end() || cur.b == lst.end())
                continue;
            if (std::next(cur.a) != cur.b)
                continue;

            ll newv = cur.a->v + cur.b->v;
            if (newv != cur.sum)
                continue;

            auto a = cur.a;
            auto b = cur.b;

            if (a->v > b->v)
                bad--;

            auto left = (a == lst.begin()) ? lst.end() : std::prev(a);
            auto right = std::next(b);

            if (left != lst.end()) {
                if (left->v > a->v && left->v <= newv)
                    bad--;
                if (left->v <= a->v && left->v > newv)
                    bad++;
            }

            if (right != lst.end()) {
                if (b->v > right->v && newv <= right->v)
                    bad--;
                if (b->v <= right->v && newv > right->v)
                    bad++;
            }

            a->v = newv;
            removed[b->id] = 1;
            lst.erase(b);

            if (left != lst.end())
                pq.push(Item(left, a));
            if (right != lst.end())
                pq.push(Item(a, right));

            ops++;
        }

        return ops;
    }
};
