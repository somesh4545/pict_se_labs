import java.util.*;

public class PayPal implements Strategy {

    int balance;
    private String emailID, password;

    PayPal(String emailID, String password){
        balance = 10000;
        this.emailID = emailID;
        this.password = password;
    }

    @Override
    public void pay(int amount){
        if(amount < balance)
            System.out.println("Your paypal account has been debited by "+amount+" Account balace now is "+(balance-amount));
        else
            System.out.println("Not enough fund");
    }
}