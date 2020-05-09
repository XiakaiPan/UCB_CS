/* Disc05-2.OHQueue */

/**
 * The goal for this question is to create an iterable Office Hours queue. We’ll do so
 * step by step.
 */

/**
 * The code below for OHRequest represents a single request. Like an IntNode, it has
 * a reference to the next request. description and name contain the description of
 * the bug and name of the person on the queue.
 */
public class OHRequest {
    public String description;
    public String name;
    public OHRequest next;

    public OHRequest(String description, String name, OHRequest next) {
        this.description = description;
        this.name = name;
        this.next = next;
    }
}
