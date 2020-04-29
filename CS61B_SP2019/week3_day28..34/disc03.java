public class Disc03 {
	public class SLList {
		private class IntNode {
			public int item;
			public IntNode next;
			public IntNode(int item, IntNode next) {
				this.item = item;
				this.next = next;
			}
		}

		private IntNode first;

		public void addFirst(int x) {
			first = new IntNode(x, first);
		}

		public void insert(int item, int postion) {
			if (first == null || postion == 0) {
				addFirst(item);
				return;
			}
			IntNode currentNode = first;
			while (postion > 1 && currentNode.next != null) {
				postion--;
				currentNode = currentNode.next;
			}
			IntNode newNode = new IntNode(item, currentNode.next);
			currentNode.next = newNode;
		}

		public void reverse(IntNode x) {
			if (first == null || first.next == null) return;
			IntNode ptr = first.next;
			first.next = null;
			while (ptr != null) {
				IntNode temp = ptr.next;
				ptr.next = first;
				first = ptr;
				ptr = temp;	
			} 
		}

		public void reverseRecur() {
			first = reverseHelper(first);
		}

		private IntNode reverseHelper(IntNode lst) {
			if (lst == null || lst.next == null) {
				return lst;
			} else {
				IntNode endOfReversed = lst.next;
				IntNode reversed = reverseHelper(lst.next);
				endOfReversed.next = lst;
				lst.next = null;
				return reversed;
			}
		}

		public static int[] insert(int[] arr, int item, int position) {
			int[] result = new int[arr.length + 1];
			position = Math.min(arr.length, position);
			for (inti = 0; i < position; i++) {
				result[i] = arr[i];
			}
			result[position] = item;
			for (int i = position; i < arr.length; i++) {
				result[i + 1] = arr[i];
			}
			return result;
		}

		public static void reverse(int[] arr) {
			for (int i = 0; i < arr.length/2; i++) {
				int j = arr.length - i - 1;
				int temp = arr[i];
				arr[i]  = arr[j];
				arr[j] = temp;
			}
		}

		public static int[] replicate(int[] arr) {
			int total = 0;
			for (int item: arr) {
				total += item;
			}
			int[] result = new int[total];
			int i = 0;
			for (int counter = 0; counter < item; counter++) {
				result[i] = item;
				i++;
			}
		}
	}
}