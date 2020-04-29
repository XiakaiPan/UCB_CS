public class ArrayDeque<T> {
    private T[] items;
    private int size;
    private int capacity = 16;

    public ArrayDeque() {
        items = (T[]) new Object[capacity];
        size = 0;
    }

    public void resize() {
        capacity *= 2;
        T[] a = (T[]) new Object[capacity];
        System.arraycopy(items, 0, a, 0, size);
        items = a;
    }

    public ArrayDeque(ArrayDeque other) {
        size = other.size;
        while (capacity < size) {
            resize();
        }
        System.arraycopy(other, 0, items, 0, other.size);
    }


    public void addFirst(T item) {
        if (size + 1 > capacity) {
            resize();
        }
        T[] a = (T[]) new Object[capacity];
        System.arraycopy(items, 0, a, 1, size);
        a[0] = item;
        items = a;
        size += 1;
    }

    public void addLast(T item) {
        if (size + 1 >= capacity) {
            resize();
        }
        size += 1;
        items[size] = item;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void printDeque() {
        int i = 0;
        while (i < size) {
            System.out.print(items[i] + " ");
        }
    }

    public T removeFirst() {
        T firstItem = items[0];
        System.arraycopy(items, 1, items, 0, size - 1);
        return firstItem;
    }

    public T removeLast() {
        T x = get(size - 1);
        size -= 1;
        return x;
    }

    public T get(int index) {
        return items[index];
    }
}
