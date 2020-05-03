public class DMSList {
    private IntNode sentinel;

    public DMSList() {
        sentinel = new IntNode(-1000, new LastIntNode()/*1*/);
    }

    public class IntNode {
        public int item;
        public IntNode next;

        public IntNode(int i, IntNode h) {
            item = i;
            next = h;
        }

        public int max() {
            return Math.max(item, next.item);
        }
    }

    public /*2*/ class LastIntNode extends IntNode {
        /*3*/
        public LastIntNode() {
            super(0, null);
        }

        @Override
        public int max() {
            return 0;
        }
    }

    /* Returns 0 if list is empty. Otherwise, returns the max elements. */
    public int max() {
        return sentinel.next.max();
    }


    public static void main(String[] args) {
        DMSList lst = new DMSList();

        System.out.println(lst.max());
    }
}
