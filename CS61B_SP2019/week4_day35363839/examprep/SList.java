public class SList {
    public class IntNode {
        public int item;
        public IntNode next;

        public IntNode(int i, IntNode n) {
            item = i;
            next = n;
        }
    }

    private static IntNode sentinel;

    public SList() {
        sentinel = new IntNode(982734, null);
    }

    public void insertFront(int x) {
        sentinel.next = new IntNode(x, sentinel.next);
    }

    public int getFront() {
        if (sentinel.next == null) {
            return -1;
        }
        return sentinel.next.item;
    }

    public static void main(String[] args) {
        SList s1 = new SList();
        SList s2 = new SList();
        s1.insertFront(1);
        s1.insertFront(2);
        System.out.println("On a correct implementation: ");
        System.out.println("These should not be equal: " + s1.getFront() + " " + s2.getFront());
        System.out.println(s1.getFront() + " == 1");
    }
}
