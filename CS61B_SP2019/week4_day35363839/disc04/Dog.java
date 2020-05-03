/**
 * Disc04
 * Part 3: Raining Cats and Dogs
 */

/* 3.1 Class Dog and class TestAnimals. */
// class Dog:
public class Dog extends Animals {
	public Dog(String name, int age) {
		super(name, age);
		noise = "Woof!";
	}

	@Override
	public void  greet() {
		System.out.println("Dog " + name + " says " + makeNoise());
	}

	public void playFetch() {
		System.out.println("Fetch " + name + "!");
	}
}