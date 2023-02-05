import java.util.Scanner;

class Vehicle {
    String registrationNumber;
    String color;
    String typeOfVehicle;

    public Vehicle(String registrationNumber, String color, String typeOfVehicle) {
        this.registrationNumber = registrationNumber;
        this.color = color;
        this.typeOfVehicle = typeOfVehicle;
    }

    void displayDetails() {
        System.out.println("Registration Number: " + registrationNumber);
        System.out.println("Color: " + color);
        System.out.println("Type of Vehicle: " + typeOfVehicle);
    }
}

class Car extends Vehicle {
    String make;
    int cc;
    String fuelType;

    public Car(String registrationNumber, String color, String typeOfVehicle, String make, int cc, String fuelType) {
        super(registrationNumber, color, typeOfVehicle);
        this.make = make;
        this.cc = cc;
        this.fuelType = fuelType;
    }

    void displayDetails() {
        super.displayDetails();
        System.out.println("Make: " + make);
        System.out.println("CC: " + cc);
        System.out.println("Fuel Type: " + fuelType);
    }
}

class Truck extends Vehicle {
    String make;
    int cc;
    String fuelType;

    public Truck(String registrationNumber, String color, String typeOfVehicle, String make, int cc, String fuelType) {
        super(registrationNumber, color, typeOfVehicle);
        this.make = make;
        this.cc = cc;
        this.fuelType = fuelType;
    }

    void displayDetails() {
        super.displayDetails();
        System.out.println("Make: " + make);
        System.out.println("CC: " + cc);
        System.out.println("Fuel Type: " + fuelType);
    }
}

class Motorcycle extends Vehicle {
    String make;
    int cc;
    String fuelType;

    public Motorcycle(String registrationNumber, String color, String typeOfVehicle, String make, int cc,
            String fuelType) {
        super(registrationNumber, color, typeOfVehicle);
        this.make = make;
        this.cc = cc;
        this.fuelType = fuelType;
    }

    void displayDetails() {
        super.displayDetails();
        System.out.println("Make: " + make);
        System.out.println("CC: " + cc);
        System.out.println("Fuel Type: " + fuelType);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the details of the car: ");
        System.out.print("Registration Number: ");
        String regNum = sc.nextLine();
    }
}