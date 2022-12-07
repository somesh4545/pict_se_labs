import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int op = 0;
        CarFactory carFactory = new CarFactory();
        do {
            System.out.print(
                    "\nEnter car type 1.Small car, 2.Sedan Car, 3.Luxury Car, 4.Exit: ");
            op = sc.nextInt();

            switch (op) {
                case 1:
                    Car obj = carFactory.buildCar("sedan");
                    obj.input();
                    obj.display(obj);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:
                    System.out.println("\nProgram ends");
                    break;
                default:
                    System.out.println("Invalid input");
            }
        } while (op != 4);

    }
}