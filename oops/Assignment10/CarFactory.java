public class CarFactory {

    public Car buildCar(CarType cartype){
        switch(cartype){
            case SMALL:
                return new SmallCar();
            case SEDAN:
                return new SedanCar();

            case LUXURY:
                return new LuxuryCar();
        }
        return null;
    }

}
