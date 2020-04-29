public class LinkedList {

	public static class IntList {

		public int sentinel;
		public IntList rest;

		public IntList(int f, IntList r) {
			sentinel = f;
			rest = r;
		}

		public void addsentinel(int x) {
			sentinel = x;
			rest = this;
		}

		public int size() {
			if (rest == null) {
				return 1;
			}
			return 1 + this.rest.size();
		}

		public int iterativeSize() {
			IntList p = this;
			int totalSize = 0;
			while (p != null) {
				totalSize += 1;
				p = p.rest;
			}
			return totalSize;
		}

		public int get(int i) {
			if (i == 0) return sentinel;
			// else if (i >= this.iterativeSize()) return POSITIVE_INFINITY;
			else {
				IntList p = rest;
				return p.get(i-1);
			}
		}

		public int iterativeGet(int i) {
			int j = 0;
			IntList p = this;
			while (j < i && i < this.iterativeSize()) {
				p = p.rest;
				j++;
			}
			// if (i < this.iterativeSize()) 
			return p.sentinel;
			// else return NEGATIVE_INFINITY;
		}
	}

	public static class SLList {

		private static class IntNode {
			public int item;
			public IntNode next;

			public IntNode(int i, IntNode n) {
				item = i;
				next = n;
				System.out.println(size);
			}
		}
		
		/* 	IntNodes are hard to work with, so we create a separate 
		 *	class called SLList that user will interact with.
		 */
		private IntNode sentinel;
		private int size;

		public SLList(int x) {
			sentinel = new IntNode(x, null);
			sentinel.next = new IntNode(x, null);
			size = 1;
		}

		public SLList() {
			sentinel = null;
			size = 0;
		}

		/** Adds an item to the front of the list. */
		public void addsentinel(int x) {
			sentinel = new IntNode(x, sentinel);
			size += 1;
		}

		/** Retrives the front item from the list. */
		public int getsentinel() {
			return sentinel.item;
		}

		/** Adds an item to the end of the lists. */
		public void addLast(int x) {
			size += 1;

			if (sentinel == null) {
				sentinel = new IntNode(x, null);
				return;
			}

			IntNode p = sentinel;

			/* Advance p to the end of the list. */
			while (p.next != null) {
				p = p.next;
			}
			p.next = new IntNode(x, null);
		}

		/** Returns the size of the list starting at IntNode p. */
		private static int size(IntNode p) {
			if (p.next == null) {
				return 1;
			}
			return  1 + size(p.next);
		}

		public int size() {
			return size(sentinel);
		}
		public int Size() {
			return size;
		}
	}

	public class TroubleMaker {
		public void main(String[] args) {
			SLList Ltm = new SLList(15);
			Ltm.addsentinel(10);
			Ltm.sentinel.next.next = Ltm.sentinel.next;
		}
	}

	public static class AList {
		private Item[] items;
		private int size;

		/** Creates an empty list. */
		public AList() {
			items = (Item[]) new Object[100];
			size = 0;
		}

		/** Resizes the underlying array to the target capacity. */
		private void resize(int capacity) {
			Item[] a = (Item[]) new Object[capacity];
			System.arraycopy(items, 0, a, 0, size);
		}

		/** Inserts x into the back of the list. */
		public void addLast(Item x) {
			if (size == items.length) {
				resize(size + 1);
			}

			items[size] = x;
			size += 1;
		}

		/** Returns the item from the back of the list. */
		public void getLast() {
			return items[size - 1];
		}
		/** Gets the ith item in the list (0 is the front). */
		public Item get(int i) {
			return items[i];
		}

		/** Returns the number of items in the list. */
		public int size() {
			return size;
		}

		/** Deletes item from back of the list and 
		  * returns deleted item. */
		public Item removeLast() {
			Item x = getLast();
			items[size - 1] = null;
			size = size - 1;
			return x;
		}
	}


	public static void main(String[] args) {
		/* IntList */
		IntList L = new IntList(15, null);
		L = new IntList(10, L);
		L = new IntList(5, L);

		System.out.println("L.get(0): " + L.get(0));
		System.out.println("L.iterativeGet(0): " + L.iterativeGet(0));
		System.out.println("L.get(1): " + L.get(1));
		System.out.println("L.iterativeGet(1): " + L.iterativeGet(1));
		System.out.println("L.get(2): " + L.get(2));
		System.out.println("L.iterativeGet(2): " + L.iterativeGet(2));
		//System.out.println("L.get(10): " + L.get(10));
		//System.out.println("L.iterativeGet(10): " + L.iterativeGet(10));

		/* SLList */
		// No null for user:
		IntList L1 = new IntList(5, null);
		SLList L2 = new SLList(5);
		/* Compare the following with the IntList initialization.
		 * There are less details for user.
		 */
		SLList Ls = new SLList(15);
		Ls.addsentinel(10);
		Ls.addsentinel(5);
		int x = Ls.getsentinel();
	}
}