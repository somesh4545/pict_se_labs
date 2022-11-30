
import java.util.*;

public class Assign6 {
	public static void main(String args[]) {
		int num1;
		int num2;
		Scanner sc = new Scanner(System.in);
		try {
			System.out.print("Enter num1: ");
			num1 = Integer.parseInt(sc.next());
			System.out.print("Enter num2: ");
			num2 = sc.nextInt();

			int res = num1 / num2;
			System.out.println("\nDivision of num1 and num2 is: " + res);

		} catch (NumberFormatException e) {
			System.out.println("The values should be integer - NumberFormatException");
		} catch (ArithmeticException e) {
			System.out.println("The num should not be zero - ArithmeticException");
		} catch (InputMismatchException e) {
			System.out.println("The values should be integer - InputMismatchException");
		}
	}
}
