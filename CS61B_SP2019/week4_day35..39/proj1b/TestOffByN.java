import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestOffByN {
    static int n = 3;
    static CharacterComparator offByN = new OffByN(n);

    // Your tests go here.
    @Test
    public void testEqualChars() {
        assertTrue(offByN.equalChars('a', 'd'));
        assertFalse(offByN.equalChars('a', 'c'));

        assertFalse(offByN.equalChars('&', '%'));
        assertFalse(offByN.equalChars('&', 's'));

        assertTrue(offByN.equalChars('z', 'w'));
        assertTrue(offByN.equalChars('f', 'c'));

        assertFalse(offByN.equalChars('a', 'a'));
        assertFalse(offByN.equalChars('h', 'h'));
    }
}
