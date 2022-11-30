import java.util.*;

public class Assign6_2 {
	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		int arr[] = new int[4];

		System.out.print("Enter values in array: ");
		try {
			for (int i = 0; i < 5; i++) {
				arr[i] = sc.nextInt();
			}
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("\nArray out of bounds Exception has occured ");
		}
	}
}
