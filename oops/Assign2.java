import java.util.Scanner;

class Publication {
    String title;
    int price, copies;

    int saleCopy() {
        System.out.println("Total Sale of Publication is " + (price * copies));
        return price * copies;
    }
}

class Book extends Publication {
    String author;

    void orderCopies() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter title of the Book: ");
        title = sc.nextLine();
        System.out.print("Enter name of the Author: ");
        author = sc.nextLine();
        System.out.print("Enter Price: ");
        price = sc.nextInt();
        System.out.print("Enter number of Copies: ");
        copies = sc.nextInt();
    }

    int saleCopy() {
        return copies * price;
    }

    void display() {
        System.out.println("\nBook Details");
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price per Copy: " + price);
        System.out.println("No. of Copies: " + copies);
        System.out.println("-----------------");
    }
}

class Magazine extends Publication {
    int current_issue;

    void receiveIssue() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter title of the Magazine: ");
        title = sc.nextLine();
        System.out.print("Enter Current Issue No.: ");
        current_issue = sc.nextInt();
        System.out.print("Enter Price: ");
        price = sc.nextInt();
        System.out.print("Enter number of Copies: ");
        copies = sc.nextInt();
    }

    int saleCopy() {
        return copies * price;
    }

    void display() {
        System.out.println("\nMagazine Details");
        System.out.println("Title: " + title);
        System.out.println("Issue No.: " + current_issue);
        System.out.println("Price per Copy: " + price);
        System.out.println("No. of Copies: " + copies);
        System.out.println("-----------------");
    }
}

public class Assign2 {
    public static void main(String[] args) {
        Book b1 = new Book();
        b1.orderCopies();
        b1.display();
        System.out.println("Total Sale of Books is " + b1.saleCopy());
        System.out.println();

        Magazine m1 = new Magazine();
        m1.receiveIssue();
        m1.display();
        System.out.println("Total Sale of Magazine is " + m1.saleCopy());
        System.out.println();

        System.out.println("Total Sale of Publication is " + (b1.saleCopy() + m1.saleCopy()));
    }
}