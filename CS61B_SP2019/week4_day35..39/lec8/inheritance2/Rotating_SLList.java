public class Rotating_SLList<T> extends S_LList<T> {
    public static Rotating_SLList rotateRight(S_LList lst) {
        Rotating_SLList nwlst = new Rotating_SLList();

        for (int i = 0; i < lst.size(); i++) {
            nwlst.addFirst(lst.get(i));
        }
        return nwlst;
    }

    public static void main(String[] args) {
        Rotating_SLList lst = new Rotating_SLList();
        lst.addLast(10);
        lst.addFirst(5);
        lst.addLast(22);
        lst.print();

        Rotating_SLList nwlst = rotateRight(lst);
        nwlst.print();
    }
}
