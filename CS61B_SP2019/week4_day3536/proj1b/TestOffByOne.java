import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestOffByOne {
    // You must use this CharacterComparator and not instantiate
    // new ones, or the autograder might be upset.
    static CharacterComparator offByOne = new OffByOne();

    // Your tests go here.
    @Test
    public void testEqualChars() {
        assertTrue(offByOne.equalChars('a', 'b'));
        assertFalse(offByOne.equalChars('a', 'e'));

        assertTrue(offByOne.equalChars('&', '%'));
        assertFalse(offByOne.equalChars('&', 's'));

        assertFalse(offByOne.equalChars('z', 'a'));
        assertFalse(offByOne.equalChars('f', 'c'));

        assertFalse(offByOne.equalChars('a', 'a'));
        assertFalse(offByOne.equalChars('h', 'h'));
    }
}
/* Uncomment this class once you've created your CharacterComparator interface and OffByOne class. **/
