import java.util.*;

class Employee {
	int emp_id;
	String emp_name, address, mail_id, mobile_no;

	Employee() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter employee id: ");
		emp_id = sc.nextInt();
		System.out.print("Enter employee name: ");
		emp_name = sc.next();
		System.out.print("Enter employee address: ");
		sc.nextLine();
		address = sc.nextLine();
		System.out.print("Enter employee mail id: ");
		mail_id = sc.next();
		System.out.print("Enter employee mobile no: ");
		mobile_no = sc.next();
	}

	void generatePaySlip(double bp) {
		double da = bp * .97, hra = bp * .10, pf = bp * .12, scf = bp * .01;
		double gross_salary = da + hra + pf + scf;
		double net_salary = gross_salary - pf - scf;

		System.out.printf("\n%-30s %s\n", "Salary distribution", "in Rs");

		System.out.printf("%-30s %s\n", "Direct allowance", da);
		System.out.printf("%-30s %s\n", "House rent allowance", hra);
		System.out.format("%-30s %s\n", "Provident fund", pf);
		System.out.format("%-30s %s\n", "Staff club fund", scf);
		System.out.println("---------------------------------");
		System.out.format("%-30s %s\n", "Gross salary", gross_salary);
		System.out.format("%-30s %s\n", "Net salary", net_salary);
	}
}

class Programmer extends Employee {
	double bp = 100000;

	Programmer() {
		super();
		super.generatePaySlip(bp);
	}
}

class TeamLead extends Employee {
	double bp = 130000;

	TeamLead() {
		super();
		super.generatePaySlip(bp);
	}
}

class AssitantProjectManager extends Employee {
	double bp = 140000;

	AssitantProjectManager() {
		super();
		super.generatePaySlip(bp);
	}
}

class ProjectManager extends Employee {
	double bp = 160000;

	ProjectManager() {
		super();
		super.generatePaySlip(bp);
	}
}

public class Assign3 {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int op = 0;
		do {
			System.out.print(
					"\nEnter type 1.Programmer, 2.Team Lead, 3.Assitant Project Manager, 4.Project Manager, 5.Exit: ");
			op = sc.nextInt();

			switch (op) {
				case 1:
					Programmer p = new Programmer();
					break;
				case 2:
					TeamLead tp = new TeamLead();
					break;
				case 3:
					AssitantProjectManager apm = new AssitantProjectManager();
					break;
				case 4:
					ProjectManager pm = new ProjectManager();
					break;
				case 5:
					System.out.println("\nProgram ends");
					break;
				default:
					System.out.println("Invalid input");
			}
		} while (op != 5);
	}

}
