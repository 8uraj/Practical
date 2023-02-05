import java.util.Scanner;

class Student {
    private String name;
    private String city;
    private int age;

    public void addData(String name, String city, int age) {
        this.name = name;
        this.city = city;
        this.age = age;
    }

    public void printData() {
        System.out.println("Name: " + name);
        sc.nextLine();
        System.out.println("City: " + city);
        System.out.println("Age: " + age);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Student s1 = new Student();
        System.out.println("Enter the details of student 1: ");
        System.out.print("Name: ");
        String name = sc.nextLine();
        System.out.print("City: ");
        String city = sc.nextLine();
        System.out.print("Age: ");
        int age = sc.nextInt();
        s1.addData(name, city, age);

        Student s2 = new Student();
        System.out.println("Enter the details of student 2: ");
        System.out.print("Name: ");
        String name1 = sc.nextLine();
        System.out.print("City: ");
        String city1 = sc.nextLine();
        System.out.print("Age: ");
        int age1 = sc.nextInt();
        s2.addData(name, city, age);

        System.out.println("Details of student 1: ");
        s1.printData();
        System.out.println("Details of student 2: ");
        s2.printData();
    }
}
