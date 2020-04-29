import org.junit.Test

public class Sort {

	/** Returns the smallest string in x.
	  * @source Got help with string compares from http://... */
	public static String FindSmallest(String[] x) {
		String smallest = x[0];
		for (int i = 0; i < x.length; i++) {
			int cmp = x[i].compareTo(smallest);
			if (cmp < 0) smallest = x[i];
		}
		/*
		for (int i = 0; i < x.length; i++) {
			if (x[i] < smallest) smallest = x[i];
		}
		*/
		return smallest;
	}

	public static int findSmallest(String[] x, int start) {
		int smallestIndex = 0;
		for (int i = start; i < x.length; i++) {
			int cmp = x[i].compareTo(x[smallestIndex]);
			if (cmp < 0) smallestIndex = i;
		}
		return smallestIndex;
	}

	public static void swap(String[] x, int a, int b) {
		String temp = x[a];
		x[a] = x[b];
		x[b] = temp;
	}

	/** Sorts strings destructively. */
	public static void sort(String[] x) {
		/*
		// find the smallest item
		//String 
		int smallestIndex = findSmallest(x);

		// move it to the front
		swap(x, 0, smallest);*/

		// selection sort the rest (using recursion?)
		/* sort(x[1:]); */
		sort(x, 0);
	}

	/** Sorts strings destructively starting from item start. */
	private static void sort(String[] x, int start) {
		if (start == x.length) return;
		int smallestIndex = findSmallest(x, start);
		swap(x, start, smallestIndex);
		sort(x, start + 1);
	}
}