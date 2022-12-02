// package assignment;

import java.util.Scanner;

interface Vehicle{
	public void gearChange(int g);
	public void speedUp();
	public void applyBreak();
	public void getState();
}

class Bicycle implements Vehicle{
	int gear = 0, speed=0;
	
	public void gearChange(int g) {
		gear = g;
	}
	public void speedUp() {
		speed += 10;
	}
	public void applyBreak() {
		speed -= 10;
	}
	public void getState() {
		System.out.println("Bicycle status\nSpeed = "+speed+"\nGear="+gear);
	}
}

class Car implements Vehicle{
	int gear = 0, speed=0;
	
	public void gearChange(int g) {
		gear = g;
	}
	public void speedUp() {
		speed += 30;
	}
	public void applyBreak() {
		speed -= 20;
	}
	public void getState() {
		System.out.println("Car status\nSpeed = "+speed+"\nGear="+gear);
	}
}

class Bike implements Vehicle{
	int gear = 0, speed=0;
	
	public void gearChange(int g) {
		gear = g;
	}
	public void speedUp() {
		speed += 15;
	}
	public void applyBreak() {
		speed -= 10;
	}
	public void getState() {
		System.out.println("Bike status\nSpeed = "+speed+"\nGear="+gear);
	}
}

public class Assign5 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int op = 0;
		do {
			System.out.print(
					"\nEnter vehicle 1.Bicycle, 2.Bike, 3.Car 4.Exit: ");
			op = sc.nextInt();

			switch (op) {
				case 1:
					Bicycle bi = new Bicycle();
					System.out.println("Gear up to 1 and speed up");
					bi.gearChange(1);
					bi.speedUp();
					bi.getState();
					
					System.out.println("\nSpeed up");
					bi.speedUp();
					bi.getState();
					break;
				case 2:
					Bike bike = new Bike();
					System.out.println("Gear up to 3 and speed up");
					bike.gearChange(3);
					bike.speedUp();
					bike.getState();
					
					System.out.println("\nSpeed up");
					bike.speedUp();
					bike.getState();
					
					System.out.println("\nBreak applied");
					bike.applyBreak();
					bike.getState();
					break;
				case 3:
					Car car = new Car();
					System.out.println("Gear up to 1 and speed up");
					car.gearChange(1);
					car.speedUp();
					car.getState();
					
					System.out.println("\nGear up to 2 and speed up");
					car.gearChange(2);
					car.speedUp();
					car.getState();
					
					System.out.println("\nBreak applied");
					car.applyBreak();
					car.getState();
					break;
				case 4:
					System.out.println("\nProgram ends !!");
					break;
				default:
					System.out.println("Invalid input");
			}
		} while (op != 4);
	}
}