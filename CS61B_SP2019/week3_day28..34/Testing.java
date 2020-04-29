/**
 * 3.1 Testing and Selection Sort
 * Week3-7-Testing
 */
public class Testing {
    public static class TestSort {

        /**
         * Tests the sort method of the Sort class.
         */
        public static void testSort() {
            String[] input = {"i", "have", "an", "egg"};
            String[] expected = {"an", "egg", "have", "i"};
            Sort.sort(input);
            for (int i = 0; i < input.length; i++) {
                if (!input[i].equals(expected[i])) {
                    System.out.println("Maismatch in position " + i +
                            ", expected: " + expected[i] + ", but got: " + input[i] + ".");
                    break;
                }
            }
        }

        public static void TestSort() {
            String[] input = {"i", "have", "an", "egg"};
            String[] expected = {"an", "egg", "have", "i"};
            Sort.sort(input);
            // 错误: 程序包org.junit不存在
            org.junit.Assert.assertArrayEquals(expected, input);
        }
    }

    public static class Sort {
        /**
         * Sorts strings destructively.
         */
        public static void sort(String[] x) {
        	// find the smallest item
        	// move it to the front
        	// selection sort the rest (using rrecursion?)
        }
    }

    public static void main(String[] args) {
        TestSort t = new TestSort();
        t.testSort();
        t.TestSort();
    }
}
