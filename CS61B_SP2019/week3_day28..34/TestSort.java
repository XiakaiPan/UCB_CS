// 3.1 Testing and Selection Sort
// Week3-7-Testing
public class TestSort {
	/** Tests the sort method of the sort class. */
	public static void testSort() {
		String[] input = {"i", "have", "an", "egg"};
        String[] expected = {"an", "egg", "have", "i"};
        Sort.sort(input);
        for(int i = 0; i < input.length; i++) {
        	if (!input[i].equals(expected[i])) {
        		System.out.println("Mismatch in position " + i + ", expected: " + expected[i] + ", but got: " + input[i] + ".");
                break;
        	}
        }
	}

	public static void JunitTestSort() {
		String[] input = {"i", "have", "an", "egg"};
        String[] expected = {"an", "egg", "have", "i"};
        Sort.sort(input);
        // 错误: 程序包org.junit不存在
        // org.junit.Assert.assertArrayEquals(expected, input);
	}

	/** Test the Sort.findSmallest method. */
	public static void testFindSmallest() {
		String[] input = {"i", "have", "an", "egg"};
		String expected = 2; //"an";

		String actual = Sort.findSmallest(input);
		org.junit.Assert.assertEquals(expectd, actual);

		String[] input2 = {"there", "are", "many", "pigs"};
    	String expected2 = 1; // "are";

    	String actual2 = Sort.findSmallest(input2);
    	org.junit.Assert.assertEquals(expected2, actual2);
	}

	/** Test the Sort.swap method. */
	public static void testSwap() {
		String[] input = {"i", "have", "an", "egg"};
        int a = 0;
        int b = 2;
        String[] expected = {"an", "have", "i", "egg"};

        Sort.swap(input, a, b);
        org.junit.Assert.assertArrayEquals(expected, input);
	}

	public static void main(String[] args) {
		testSort();
		JunitTestSort();
		testFindSmallest();
		testSwap();
	}
}