import java.util.*;

public class Cart{
    List<Item> items;

    Cart(){
        items = new ArrayList<Item>();
    }

    public void addITem(Item i){
        items.add(i);
    }

    public void removeItem(Item i){
        items.remove(i);
    }

    public int cartTotal(){
        int amt = 0;
        for(Item ele:items){
            amt += ele.getPrice();
        }
        return amt;
    }

    public void displayCart(){
        System.out.println("Cart items are: ");
        for(Item ele:items){
            System.out.println(ele.getProductName() + " " + ele.getPrice());
        }
        System.out.println();
    }

    public void makePayment(Strategy mode){
        int totalAmt = cartTotal();
        mode.pay(totalAmt);
    }
}