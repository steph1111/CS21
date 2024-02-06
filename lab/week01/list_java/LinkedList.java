public class LinkedList {
    LinkedList() {}

    public int size()  {
        return size_;
    }
    
    public String pop_back() {
        if (size_ == 0) throw new Error("Empty LinkedList");
        
        String old_tail_data = tail.data;
        if (size_ == 1) {
            head = tail = null;
        } else {
            tail = tail.prev;
            tail.next = null;
        }
        size_--;
        return old_tail_data;
    }

    public String pop_front() {
        if (size_ == 0) throw new Error("Empty LinkedList");
        
        String old_head_data = head.data;
        if (size_ == 1) head = tail = null;
        else {
            head = head.next;
            head.prev = null;
        }
        size_--;
        return old_head_data;
    }

    public String push_back(String val) {
        LinkNode new_node = new LinkNode(val);
        if (size_ == 0) head = tail = new_node;
        else {
            tail.next = new_node;
            new_node.prev = tail;
            tail = new_node;
        }
        size_++;
        return val;
    }

    public String push_front(String val) {
        LinkNode new_node = new LinkNode(val);
        if (size_ == 0) head = tail = new_node;
        else {
            head.prev = new_node;
            new_node.next = head;
            head = new_node;
        }
        size_++;
        return val;
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("[");
        for (LinkNode cur = head; cur != null; cur = cur.next) {
            str.append(cur.data);
            if (cur.next != null) {
                str.append(", ");
            }
        }
        str.append("]");
        return str.toString();
    }

    private class LinkNode {
        private String data;
        private LinkNode prev = null;
        private LinkNode next = null;

        private LinkNode(String data) {
            this.data = data;
        }
    }

    private LinkNode head;
    private LinkNode tail;
    private int size_ = 0;
}