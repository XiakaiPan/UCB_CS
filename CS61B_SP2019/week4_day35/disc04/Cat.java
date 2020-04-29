public class Cat extends Animals {
	public Cat(String name, int age) {
		//Animals(name, age);
	}

	@Override
	public void greet() {
		System.out.println("Cat says: " + makeNoise());
	}
}