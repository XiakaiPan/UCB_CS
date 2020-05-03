/**
 * Disc04
 * Part 3: Raining Cats and Dogs
 */

/* 3.1 Class Dog and class TestAnimals. */
// Class TestAnimals
public class TestAnimals {
	public static void main(String[] args) {
		Animals a = new Animals("Pluto", 10);
		Cat c = new Cat("Garfield", 6);
		Dog d = new Dog("Fido", 6);
		a = new Dog("Spot", 10);
		d = (Dog) a;

		a.greet();
		c.greet();
		d.greet();

		a = c;
		((Cat) a).greet();
		a.greet();
	}
}