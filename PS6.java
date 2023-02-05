abstract class Shape {
    int length;
    int width;

    public Shape(int length, int width) {
        this.length = length;
        this.width = width;
    }

    abstract void printArea();
}

class Rectangle extends Shape {

    public Rectangle(int length, int width) {
        super(length, width);
    }

    @Override
    void printArea() {
        System.out.println("The area of the rectangle is " + (length * width));
    }
}

class Triangle extends Shape {

    public Triangle(int length, int width) {
        super(length, width);
    }

    @Override
    void printArea() {
        System.out.println("The area of the triangle is " + (0.5 * length * width));
    }
}

class Circle extends Shape {

    public Circle(int length) {
        super(length, 0);
    }

    @Override
    void printArea() {
        System.out.println("The area of the circle is " + (3.14 * length * length));
    }
}

public class Main {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(10, 20);
        rect.printArea();

        Triangle tri = new Triangle(10, 20);
        tri.printArea();

        Circle cir = new Circle(10);
        cir.printArea();
    }
}
