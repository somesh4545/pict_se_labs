// Aim: Design and implement Factory design pattern for the given context. Consider Car building
// process, which requires many steps from allocating accessories to final makeup. These steps
// should be written as methods and should be called while creating an instance of a specific car type.
// Hatchback, Sedan, SUV could be the subclasses of Car class. Car class and its subclasses,
// CarFactory and TestFactoryPattern should be implemented.

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
                    Car obj = carFactory.buildCar(CarType.SMALL);
                    obj.input();
                    obj.display(obj);
                    break;
                case 2:
                    Car obj1 = carFactory.buildCar(CarType.SEDAN);
                    obj1.input();
                    obj1.display(obj1);
                    break;
                case 3:
                    Car obj2 = carFactory.buildCar(CarType.LUXURY);
                    obj2.input();
                    obj2.display(obj2);
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