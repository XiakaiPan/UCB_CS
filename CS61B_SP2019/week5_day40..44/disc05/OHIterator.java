import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * First, let’s define an iterator. Create a class OHIterator that implements an
 * iterator over OHRequest objects that only returns requests with good
 * descriptions. Our OHIterator’s constructor will take in an OHRequest object
 * that represents the first OHRequest object on the queue. We’ve provided a
 * function, isGood, that accepts a description and says if the description
 * is good or not.
 */

public class OHIterator implements Iterator<OHRequest> {

    OHRequest curr;

    public OHIterator(OHRequest original) {
        curr = original;
    }

    public boolean isGood(String description) {
        return description != null && description.length() > 5;
    }

    @Override
    public boolean hasNext() {
        while (curr != null && !isGood(curr.description)) {
            curr = curr.next;
        }
        return curr != null;
    }

    @Override
    public OHRequest next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        OHRequest currRequest = curr;
        curr = curr.next;

        return currRequest;
    }
}