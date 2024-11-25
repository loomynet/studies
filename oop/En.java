public class En {
    public static class Vehicle {
        private String make;
        private String model;
        private int year;
        private int numberOfWheels;

        public Vehicle (String make, String model, int year, int numberOfWheels) {
            this.make = make;
            this.model = model;
            this.year = year;
            if (numberOfWheels < 2) {
                throw new IllegalArgumentException("expected number of wheels to be greater than or equal to 2, but was " + numberOfWheels);
            } else {
                this.numberOfWheels = numberOfWheels;
            }
        }
        
        public void displayDetails() {
            System.out.println("Make: " + make);
            System.out.println("Model: " + model);
            System.out.println("Year: " + year);
            System.out.println("Number of wheels: " + numberOfWheels);
        }
    }

    public static class Car extends Vehicle {
        private int numberOfDoors;

        public Car (String make, String model, int year, int numberOfWheels, int numberOfDoors) {
            super(make, model, year, numberOfWheels);
            this.numberOfDoors = numberOfDoors;
        }

        @Override
        public void displayDetails() {
            super.displayDetails();
            System.out.println("Number of doors: " + this.numberOfDoors);
        }
    }

    public static class Motorcycle extends Vehicle {
        private boolean hasSideCar;

        public Motorcycle (String make, String model, int year, int numberOfWheels, boolean hasSideCar) {
            super(make, model, year, numberOfWheels);
            this.hasSideCar = hasSideCar;
        }

        @Override
        public void displayDetails() {
            super.displayDetails();
            System.out.println("Has side car? : " + (this.hasSideCar ? "Yes" : "No"));
        }
    }

    public static class Truck extends Vehicle {
        private int payloadCapacity;

        public Truck (String make, String model, int year, int numberOfWheels,int payloadCapacity) {
            super(make, model, year, numberOfWheels);
            this.payloadCapacity = payloadCapacity;
        }

        @Override
        public void displayDetails() {
            super.displayDetails();
            System.out.println("Payload capacity: " + this.payloadCapacity + "kg");
        }
    }
    public static void main(String[] args) {
        Vehicle[] garage = new Vehicle[3];
        Car car = new Car("Toyota","Corola",2009,4,2);
        Motorcycle motorcycle = new Motorcycle("Kawasaki","Ninja",2010, 2,false);
        Truck truck = new Truck("Volvo", "FE", 2022, 6, 1000);
        
        garage[0] = car;
        garage[1] = motorcycle;
        garage[2] = truck;
        
        for (Vehicle vehicle : garage) {
            System.out.println("---- Vehicle Details ----");
            vehicle.displayDetails();
            System.out.println();
        }
    }
}
