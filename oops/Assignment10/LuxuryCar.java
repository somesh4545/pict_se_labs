public class LuxuryCar extends Car{

    String features_avail;

    @Override
    void getPrice(double price) {
        if(price>10) features_avail = "YES";
        else features_avail = "NO";
    }

    @Override
    void detail(String comp, String car_n) {
        System.out.println("Company: "+comp);
        System.out.println("Car name: "+car_n);
        System.out.println("Colors: Black, White, Navy Blue, Gold, Yellow, Gray, Red Colorfull");
        System.out.println("Gear: Manual, Automatic");
    }

    @Override
    void accessories() {
        System.out.println("Types of Tyres- CEAT, MRF, Customized");
        System.out.println("Airbags- "+features_avail);
        System.out.println("Back Wiper- "+features_avail);
        System.out.println("Touch Screen Music Player- "+features_avail);
    }
}
