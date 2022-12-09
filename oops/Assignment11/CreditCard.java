import java.util.*;

public class CreditCard implements Strategy {

    int balance;
    private String accountHolder, cardNumber, cvNumber;

    CreditCard(String accountHolder, String cardNumber, String cvNumber){
        balance = 100000;
        this.accountHolder = accountHolder;
        this.cardNumber = cardNumber;
        this.cvNumber = cvNumber;
    }

    @Override
    public void pay(int amount){
        if(amount < balance)
            System.out.println("Your credit card has been debited by "+amount+" Account balace now is "+(balance-amount));
        else
            System.out.println("Not enough fund");
    }
}