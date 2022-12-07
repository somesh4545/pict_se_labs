public class CarFactory {

    public Car buildCar(String cartype){
        if(cartype.equalsIgnoreCase("Small")){
            return new SmallCar();
        }else if(cartype.equalsIgnoreCase("Luxury")){
            return new LuxuryCar();
        }else if(cartype.equalsIgnoreCase("Sedan")){
            return new SedanCar();
        }
        return null;
    }

}
