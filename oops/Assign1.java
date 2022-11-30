import java.util.*;

public class Assign1 {
    float real;
    float im;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Assign1 a1 = new Assign1();

        System.out.print("Enter the real part (C1): ");
        a1.real = sc.nextFloat();
        System.out.print("Enter the imaginary part (C1): ");
        a1.im = sc.nextFloat();

        Assign1 a2 = new Assign1();
        System.out.print("\nEnter the real part (C2): ");
        a2.real = sc.nextFloat();
        System.out.print("Enter the imaginary part (C2): ");
        a2.im = sc.nextFloat();

        System.out.println("\nC1 = " + a1.real + " + " + a1.im + "i");
        System.out.println("C2 = " + a2.real + " + " + a2.im + "i\n");

        int op = 5;
        do {

            System.out.println("\nEnter the operation you want to perform on C1 & C2");
            System.out.print("1) +  2) - 3) * 4) / 5) exit: ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    float ra = (a1.real + a2.real);
                    float ia = (a1.im + a2.im);
                    System.out.println("C1 + C2 = " + ra + " + " + ia + "i");
                    break;
                case 2:
                    float rs = (a1.real - a2.real);
                    float is = (a1.im - a2.im);
                    System.out.println("C1 - C2 = " + rs + " + " + is + "i");
                    break;
                case 3:
                    float rm = (a1.real * a2.real - a1.im * a2.im);
                    float im = (a1.real * a2.im + a1.im * a2.real);
                    System.out.println("C1 * C2 = " + rm + " + " + im + "i");
                    break;
                case 4:
                    float rd = (a1.real * a2.real + a1.im * a2.im) / (a2.real * a2.real + a2.im * a2.im);
                    float id = (-a1.real * a2.im + a1.im * a2.real) / (a2.real * a2.real + a2.im * a2.im);
                    System.out.println("C1 / C2 = " + rd + " + " + id + "i");
                    break;
                case 5:
                    System.out.println("Program executed successfully.");
                    break;
                default:
                    System.out.println("Invalid / Unsupported operation.");
            }
        } while (op != 5);
    }

}