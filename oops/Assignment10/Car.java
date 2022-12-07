import java.util.*;

abstract class Car {

    String company, car_name;
    double price;

    abstract void getPrice(double price);
    abstract void detail(String comp, String car_n);
    abstract void accessories();

    public void input(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter company name: ");
        company = sc.next();
        System.out.print("Enter car name: ");
        car_name = sc.next();
        System.out.print("Enter price in lakhs: ");
        price = sc.nextDouble();
    }

    public void display(Car obj){
        obj.getPrice(price);
        obj.detail(obj.company, obj.car_name);
        obj.accessories();
    }
}
