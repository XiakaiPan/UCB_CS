public class LinkedListDeque<T> implements Deque<T> {
    public IntNode sentinel;
    public int size;

    private class IntNode {
        private IntNode prev;
        private T item;
        private IntNode next;
    }

    public LinkedListDeque() {
        IntNode ptr = new IntNode();
        ptr.prev = ptr;
        ptr.next = ptr.prev;
        sentinel = ptr;
        size = 0;
    }

    public LinkedListDeque(LinkedListDeque other) {
        size = other.size;
        // TODO: Deep copy of other. --tricky
        // IntNode p = other.sentinel.next;
    }

    public T getRecursive(int index) {
        IntNode ptr = sentinel.next;
        // Don't consider index > size - 1
        if (index == 0) {
            return sentinel.next.item;
        } else {
            ptr = ptr.next;
            return getRecursive(index - 1);
        }
    }

    @Override
    public void addFirst(T item) {
        IntNode p = new IntNode();
        // TODO: NullPointerException.
        if (sentinel.next == null) {
            sentinel.next = p;
            p.prev = sentinel;
            p.next = sentinel;
            sentinel.prev = p;
        } else {
            p.item = item;
            p.next = sentinel.next;
            p.prev = sentinel;
            sentinel.next.prev = p;
            sentinel.next = p;
            size += 1;
        }
    }

    @Override
    public void addLast(T item) {
        IntNode p = new IntNode();
        p.item = item;
        p.prev = sentinel.prev;
        p.next = sentinel;
        sentinel.prev.next = p;
        sentinel.prev = p;
        size += 1;
    }

    public boolean isEmpty() {
        return sentinel.next == sentinel;
    }

    public int size() {
        return size;
    }

    @Override
    public void printDeque() {
        IntNode p = sentinel.next;
        do {
            System.out.println(p.item);
            p = p.next;
        } while (p != sentinel);
    }

    public T removeFirst() {
        IntNode p = sentinel.next;
        p.next.prev = p.prev;
        sentinel.next = p.next;
        return p.item;
    }

    @Override
    public T removeLast() {
        IntNode p = sentinel.prev.prev;
        p.next = sentinel;
        sentinel.prev = p;
        return p.next.item;
    }

    @Override
    public T get(int index) {
        int i = 0;
        IntNode p = sentinel.next;
        while (i < index) {
            p = p.next;
            i += 1;
        }
        return p.item;
    }
}
