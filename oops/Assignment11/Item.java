import java.util.*;

public class Item{
    public String productName;
    public int price;

    Item(String productName, int price){
        this.productName = productName;
        this.price = price;
    }

    public int getPrice(){
        return price;
    }

    public String getProductName(){
        return productName;
    }
}