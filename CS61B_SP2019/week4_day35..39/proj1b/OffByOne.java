public class OffByOne implements CharacterComparator {
    @Override
    public boolean equalChars(char x, char y) {
        // return (Math.abs((int) x - (int) y) == 1);
        return x - y == 1 || y - x == 1;
    }
}
