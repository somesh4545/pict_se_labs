import java.util.*;

abstract class Shape {
	abstract void area();
}

class Triangle extends Shape {
	void area() {
		Scanner sc = new Scanner(System.in);
		int h, b;
		System.out.print("Enter height of triangle: ");
		h = sc.nextInt();
		System.out.print("Enter base of triangle: ");
		b = sc.nextInt();

		double area_t = 0.5 * h * b;
		System.out.println("Area of triangle is: " + area_t);
	}
}

class Rectangle extends Shape {
	void area() {
		Scanner sc = new Scanner(System.in);
		int l, w;
		System.out.print("\nEnter length of rectangle: ");
		l = sc.nextInt();
		System.out.print("Enter width of rectangle: ");
		w = sc.nextInt();

		double area_r = l * w;
		System.out.println("Area of rectangle is: " + area_r);
	}
}

public class Assign4 {

	public static void main(String args[]) {
		Shape s = new Triangle();
		s.area();

		s = new Rectangle();
		s.area();
	}

}
