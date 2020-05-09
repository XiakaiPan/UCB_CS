import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.function.Predicate;

/**
 * We want to make a FilteredList class that selects only certain elements of a List
 * during iteration. To do so, we’re going to use the Predicate interface defined below.
 * Note that it has a method, test that takes in an argument and returns True if we
 * want to keep this argument or False otherwise.
 * public interface Predicate<T> { boolean test (T x); }
 */

/**
 * For example, if L is any kind of object that implements List<String> (that is, the
 * standard java.util.List), then writing
 * FilteredList<String> FL = new FilteredList<String> (L, filter);
 * gives an iterable containing all items, x, in L for which filter.test(x) is True.
 * Here, filter is of type Predicate. Fill in the FilteredList class below.
 */

public class FilteredList<T> implements Iterable<T> {
    List<T> list;
    Predicate<T> pred;

    public FilteredList(List<T> L, Predicate<T> filter) {
        this.list = L;
        this.pred = filter;
    }


    @Override
    public Iterator<T> iterator() {
        return new FilteredListIterator(list, pred);
    }

    private class FilteredListIterator implements Iterator<T> {
        List<T> list;
        Predicate<T> pred;
        int index;

        public FilteredListIterator(List<T> list, Predicate<T> pred) {
            this.list = list;
            this.pred = pred;
            index = 0;
        }

        @Override
        public boolean hasNext() {
            while (index < list.size() && !pred.test(list.get(index))) {
                index++;
            }
            return index < list.size();
        }

        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            index++;
            return list.get(index - 1);
        }
    }
}
