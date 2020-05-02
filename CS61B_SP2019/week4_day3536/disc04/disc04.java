/**
 * 2.1 Creating Cats
 */
public class disc04 {
	public static class Animal {
		protected String name, noise;
		protected int age;

		public Animal(String name, int age) {
			this.name = name;
			this.age = age;
			this.noise = "Huh?";
		}

		public String makeNoise() {
			if (age < 5) {
				return noise.toUpperCase();
			} else {
				return noise;
			}
		}

		public void greet() {
			System.out.println("Animal " + name + " says: " + makeNoise());
		}
	}

	public static Cat extends Animals {
		public Cat(String name, int age) {
			Animals(name, age);
		}

		@Override
		public void greet() {
			System.out.println("Cat says: " + noise);
		}
	}
}