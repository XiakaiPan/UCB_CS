public class Demo {

    public static void main(String[] args) {
        List_61B<String> someList = new S_LList<>();
        someList.addFirst("elk");
        someList.addLast("dwell");
        someList.addLast("on");
        someList.addLast("existential");
        someList.addLast("crises");
        someList.print();
        /**
         * When Java runs a method that is overriden, it searches for
         * the appropriate method signature in it's dynamic type and runs it.
         * This does not work for overloaded methods!
         */
    }
}
