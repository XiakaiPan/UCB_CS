public class D extends Inheritance{
		public static void main (String[] args) {
			// B a0 = (B) new A();  Dynamic type must be B or subclass of B
			// a0.m1();
 			// a0.m2(16);

			A b0 = new B();
			System.out.println(b0.x);
			b0.m1();
			b0.m2();
			// ((B)b0).m2(61);

			B b1 = new B();
			b1.m2(61);
			b1.m3();

			A c0 = new C();
			c0.m2();

			// C c1 = new C();
			A a1 = (A) c0;	
			C c2 = (C) a1;
			c2.m3();
			// c2.m4();
			c2.m5();

			((C) c0).m3();
			// (C) c0.m3();
			b0.update();
			b0.m1();
		}
	}