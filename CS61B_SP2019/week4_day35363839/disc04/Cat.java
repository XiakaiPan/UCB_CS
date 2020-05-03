public class Cat extends Animals {
	public Cat(String name, int age) {
		// @source
		super(name, age);
		this.noise = "Meow";
	} 

	@Override
	public void greet() {
		System.out.println("Cat " + name + " says: " + makeNoise());
	}
}