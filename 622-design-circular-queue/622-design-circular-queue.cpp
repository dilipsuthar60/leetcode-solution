class MyCircularQueue 
{
public:
    struct listnode
    {
        int val;
        listnode*next;
        listnode*prev;
        listnode(int val)
        {
            this->val=val;
        }
    };
    int max_size;
    int size;
    listnode*head;
    listnode*tail;
    MyCircularQueue(int k) 
    {    
        max_size=k;
        size=0;
        head=new listnode(-1);
        tail=new listnode(-1);
        head->next=tail;
        tail->prev=head;
    }
    bool enQueue(int value) 
    {     
        if(size==max_size)
        {
            return false;
        }
        size++;
        listnode*new_node=new listnode(value);
        listnode*neb=tail->prev;
        
        new_node->next=tail;
        new_node->prev=neb;
        
        tail->prev=new_node;
        neb->next=new_node;
        return true;
    }
    void del(listnode*node)
    {
        listnode*prev_node=node->prev;
        listnode*next_node=node->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
        delete node;
    }
    bool deQueue() 
    {   
        if(size==0)
        {
            return false;
        }
        size--;
        del(head->next);
        return true;
    }
    int Front() 
    {   
        return head->next->val;
    }
    int Rear() 
    {   
        return tail->prev->val;
    }
    bool isEmpty() 
    {   
        if(size==0)
        {
            return true;
        }
        return false;
    }
    bool isFull() 
    {   
        if(size==max_size)
        {
            return true;
        }
        return false;
    }
};
