public class Palindrome {
    public Deque<Character> wordToDeque(String word) {
        ArrayDeque<Character> arrayDeque = new ArrayDeque<>();
        for (int i = 0; i < word.length(); i++) {
            arrayDeque.addLast(word.charAt(i));
        }
        return arrayDeque;
    }

    public boolean isPalindrome(String word) {
        if (word.length() == 1 || word.length() == 0) return true;
        Deque<Character> deque = wordToDeque(word);
        for (int i = 0, j = deque.size() - 1; i != j && i <= j; i++, j--) {
            if (deque.get(i) != deque.get(j)) return false;
        }
        return true;
    }

    /**
     * To determine whether a word is a off-by-one palindrome
     *
     * @source https://github.com/zangsy/cs61b_sp19/blob/master/proj1b/Palindrome.java
     */

    private boolean isPalindrome(Deque<Character> wordInDeque, CharacterComparator cc) {
        while (wordInDeque.size() > 1) {
            return cc.equalChars(wordInDeque.removeFirst(), wordInDeque.removeLast()) && isPalindrome(wordInDeque, cc);
        }
        return true;
    }

    public boolean isPalindrome(String word, CharacterComparator cc) {
        return isPalindrome(wordToDeque(word), cc);
    }
}
