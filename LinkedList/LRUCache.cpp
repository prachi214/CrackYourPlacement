class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

private:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> mpp;

    //  doubly LL
    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity)
    {
        // initialization
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_)
    {
        // if key exists in map
        if (mpp.find(key_) != mpp.end())
        {
            // map stores node reference means gives entire node
            node *resnode = mpp[key_];
            // take value
            int res = resnode->val;
            mpp.erase(key_);
            // put at front this node bcoz this is now LRU node
            deletenode(resnode);
            // insert after head
            addnode(resnode);
            mpp[key_] = head->next;
            // value
            return res;
        }
        // not exist key in map
        return -1;
    }

    void put(int key_, int value)
    {
        // when searching ele exist in map
        if (mpp.find(key_) != mpp.end())
        {
            node *existingnode = mpp[key_];
            mpp.erase(key_);
            deletenode(existingnode);
        }
        // capacity is fill

        if (mpp.size() == cap)
        {
            mpp.erase(tail->prev->key);
            // from cache
            deletenode(tail->prev);
        }
        // when key,val is new
        addnode(new node(key_, value));
        // insert after head
        mpp[key_] = head->next;
    }
};
