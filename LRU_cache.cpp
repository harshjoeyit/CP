class LRUCache {
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap) {
        unordered_map<int, Node *> temp;
        hsmap = temp;
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        count = 0;
    }

    static void addToHead(Node *node) {     // head is (0, 0)
        node->next = head->next;    // to next element of head
        node->next->pre = node;     // next element of head to new
        node->pre = head;           // new to head
        head->next = node;          // head to new
    }

    static void deleteNode(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    static int get(int key) {
        if (hsmap.count(key) > 0) {
            Node *node = hsmap[key];
            int result = node->value;
            deleteNode(node);
            addToHead(node);
            return result;
        }
        return -1;
    }

    static void set(int key, int value) {
        if (hsmap.count(key) > 0) {
            Node *node = hsmap[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        } else {
            Node *node = new Node(key, value);
            hsmap[key] = node;
            if (count < capacity) {
                count++;
                addToHead(node);
            } else {
                hsmap.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};