import java.util.Iterator;

public class OfficeHoursQueue implements Iterable<OHRequest> {
    OHRequest queue;

    public OfficeHoursQueue(OHRequest queue) {
        this.queue = queue;
    }

    @Override
    public Iterator<OHRequest> iterator() {
        return new OHIterator(queue);
    }


    /**
     * Fill in the main method below so that you make a new OfficeHoursQueue object
     * and print the names of people with good descriptions. Note : the main method is
     * part of the OfficeHoursQueue class.
     */
    public static void main(String[] args) {
        OHRequest s1 = new OHRequest("Failing my test for get in arrayDeque, NPE", "Pam", null);
        OHRequest s2 = new OHRequest("conceptual: what is dynamic method selection", "Michael", s1);
        OHRequest s3 = new OHRequest("git: what does checkout do.", "Jim", s2);
        OHRequest s4 = new OHRequest("help", "Dwight", s3);
        OHRequest s5 = new OHRequest("debugging get(i)", "Creed", s4);

        OfficeHoursQueue q = new OfficeHoursQueue(s5);
        for (OHRequest o : q) {
            System.out.println(o.name);
        }
    }
}
