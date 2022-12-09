// Aim: Implement and apply Strategy Design pattern for simple Shopping Cart where three
// payment strategies are used such as Credit Card, PayPal, BitCoin. Create the interface for
// strategy pattern and give concrete implementation for payment.'

import java.util.*;

public class Main{
    public static void main(String args[]){
        Cart cart = new Cart();


        cart.addITem(new Item("Nike shoes", 10000));
        cart.addITem(new Item("Adidas tshirt", 699));

        cart.displayCart();

        int ch=0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Select payment mode 1.Credit card 2.Paypal: ");
        ch = sc.nextInt();
        if(ch == 1){

            cart.makePayment(new CreditCard("Somesh Somani", "66175901", "912"));
        }else{

            cart.makePayment(new PayPal("someshsomani457@gmail.com", "somesh"));
        }
    }
}