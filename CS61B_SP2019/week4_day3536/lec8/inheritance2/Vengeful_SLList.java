public class Vengeful_SLList<Item> extends S_LList<Item> {
    public S_LList<Item> deletedItems;

    public Vengeful_SLList() {
        /**
         * Thus, we can either explicitly make a call to the
         * superclass's constructor, using the super keyword:
         */
        super();
        /**
         * Or, if we choose not to, Java will automatically
         * make a call to the superclass's no-argument constructor for us.
         */
        S_LList<Item> deletedItems;
    }

    public Vengeful_SLList(Item x) {
        super(x);
        deletedItems = new S_LList<Item>();
    }

    @Override
    public Item removeLast() {
        Item x = super.removeLast();

        deletedItems.addLast(x);

        return x;
    }

    public void printLostItems() {
        deletedItems.print();
    }
}
