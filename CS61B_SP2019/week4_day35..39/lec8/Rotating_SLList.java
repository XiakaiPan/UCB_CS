public class Rotating_SLList<T> extends S_LList<T> {
    public static void rotateRight(S_LList lst) {
        S_LList nwlst = new S_LList();

        for (int i = 0; i < lst.size(); i++) {
            nwlst.addLast(lst.get(i));
        }
    }

    public static void main(String[] args) {
        Rotating_SLList lst = new Rotating_SLList();
        lst.addLast(10);
        lst.addFirst(5);
        lst.addLast(22);
        lst.print();

        rotateRight(lst);
        lst.print();
    }
}
