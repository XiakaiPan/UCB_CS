public class ExamPrep03 {

	/* 1. Flatten */
	public static int[] flatten(int[][] x) {
		int totalLength = 0;

		for(int[] lst: x) {
			totalLength += lst.length;
		}

		int[] a = new int[totalLength];
		int aIndex = 0;

		for (int i = 0; i < x.length; i++) {
			System.arraycopy(x[i], 0, a, aIndex, x[i].length);
			aIndex += x[i].length;
		}

		return a;
	}

	/* 2. Skippify */
	/*
	public class IntList {
		public int first;
		public IntList rest;

		@Override
		public boolean equals(Object o) {...}
		public static IntList list(int... args) {...}

		public void Skippify() {
			IntList p = this;
			int n = 1;
			while (p != null) {
				// Answer:--????
				IntList next = p.rest;
				for (int i = 0; i < n; i++) {
					if (next == null) {
						break;
					}
					next = next.rest;
				}
				p.rest = next;
				p = p.rest;
				n++;
			}
		}
	}
	*/

	/* 3. Sans */
	public class IntList {
		public int first;
		public IntList rest;
		public IntList (int f, IntList r) {
			this.first = f;
			this.rest = r;
		}

		/** Non-destructively creats a copy of x that contains no occurences of y.*/
		public static IntList ilsans(IntList x, int y) {
			if (x == null) {
				return x;
			}
			if (x.first == y) {
				//return x.rest;
				return ilsans(x.rest, y);
			}
			return IntList(x.rest, y);
		}

		/** Destructively modify and return x to contain no occurences of y, without
		using the keyword "new".*/
		public static IntList dilsans(IntList x, int y) {
			if (x == null) {
				return x;
			}
			;
			if (x.first == y) {
				return x.rest;
			}
			return dilsans(x.rest, y);
		}
	}

	public static void main(String[] args) {

		/* 1. Flatten */
		int[][] x = {{1, 2, 3}, {}, {7, 8}};
		int[] y = flatten(x);
		for(int i = 0; i < y.length; i++) {
			System.out.print(y[i] + " ");
		}

		/* 2. Skippify */
		/*
		IntList A = IntList.list(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
		IntList B = IntList.list(9, 8, 7, 6, 5, 4, 3, 2, 1);
		A.Skippify();
		B.Skippify();
		for(int i = 0; i < A.s)
		*/

		/* 3. Sans */
		IntList a = IntList(1, null);
		a = new IntList(2, a);
		a = new IntList(3, a);
		b1 = ilsans(a, 1);
		b2 = dilsans(a, 1);
		c1 = ilsans(a, 2);
		c2 = dilsans(a, 2);
		d1 = ilsans(a, 3);
		d2 = dilsans(a, 3);
		e1 = ilsans(a, 0);
		e2 = dilsans(a, 0);
		IntList[] lst = new IntList[9];
		for(int i = 0; i < 9; i++) {
			IntList p = x[i];
			for(int j = 0; j < lst[i].length; j++) {
				System.out.print(p.first + " ");
				p = p.rest;
			}
			System.out.println();
		}
	}
}