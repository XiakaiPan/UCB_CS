package creatures;

import huglife.*;
import org.junit.Test;

import java.awt.*;
import java.util.HashMap;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;

/**
 * Tests the Clorus class
 *
 * @author Xiakai Pan
 */


public class TestClorus {

    @Test
    public void testBasics() {
        Clorus clorus = new Clorus(1.9);
        Clorus c = new Clorus();
        // name: "clorus"
        assertEquals("clorus", clorus.name());
        assertEquals("clorus", c.name());
        // color
        assertEquals(new Color(34, 0, 231), clorus.color());
        assertEquals(new Color(34, 0, 231), c.color());
        // lose 0.03 energy every move
        clorus.move();
        c.move();
        assertEquals(1.87, clorus.energy(), 0.03);
        assertEquals(0.97, c.energy(), 0.03);
        //lose 0.01 energy on a stay action
        clorus.stay();
        c.stay();
        assertEquals(1.86, clorus.energy(), 0.01);
        assertEquals(0.96, c.energy(), 0.01);
        // gain another creature's energy which was attached by Clorus
        Plip p = new Plip();
        clorus.attack(p);
        c.attack(p);
        assertEquals(2.86, clorus.energy(), 1.0);
        assertEquals(1.96, c.energy(), 1.0);
    }

    @Test
    public void testReplicate() {
        Clorus c = new Clorus(2.5);
        Clorus offSring1 = c.replicate();
        assertEquals(offSring1.energy(), c.energy(), 1.25);
        Clorus offSpring2 = offSring1.replicate();
        assertEquals(offSpring2.energy(), offSring1.energy(), 0.625);
    }

    @Test
    public void testChooseAction() {
        Clorus c = new Clorus(3.0);

        // No empty squares
        HashMap<Direction, Occupant> surrounded = new HashMap<Direction, Occupant>();
        surrounded.put(Direction.TOP, new Impassible());
        surrounded.put(Direction.BOTTOM, new Impassible());
        surrounded.put(Direction.LEFT, new Impassible());
        surrounded.put(Direction.RIGHT, new Impassible());

        Action actual = c.chooseAction(surrounded);
        Action expected = new Action(Action.ActionType.STAY);

        assertEquals(expected, actual);


        // otherwise, any plips are seen, attack one of them randomly
        c = new Clorus(1.2);
        HashMap<Direction, Occupant> toPlip = new HashMap<Direction, Occupant>();
        toPlip.put(Direction.TOP, new Plip(1.5));
        toPlip.put(Direction.BOTTOM, new Empty());
        toPlip.put(Direction.LEFT, new Plip());
        toPlip.put(Direction.RIGHT, new Plip(2.5));

        actual = c.chooseAction(toPlip);
        Action unexpected = new Action(Action.ActionType.ATTACK, Direction.BOTTOM);
        assertNotEquals(unexpected, actual);


        // otherwise, if energy >= 1, replicate to a random empty square.
        c = new Clorus(1.2);
        HashMap<Direction, Occupant> allEmpty = new HashMap<Direction, Occupant>();
        allEmpty.put(Direction.TOP, new Empty());
        allEmpty.put(Direction.BOTTOM, new Empty());
        allEmpty.put(Direction.LEFT, new Empty());
        allEmpty.put(Direction.RIGHT, new Empty());

        actual = c.chooseAction(allEmpty);
        // TODO:
        // Action.type
        expected = new Action(Action.ActionType.REPLICATE, Direction.BOTTOM);

        assertEquals(expected.type, actual.type);


        // otherwise, the Clorus will move to a random empty square
        c = new Clorus(0.990);
        actual = c.chooseAction(allEmpty);
        expected = new Action(Action.ActionType.MOVE, Direction.BOTTOM);

        assertEquals(expected.type, actual.type);
    }

}
