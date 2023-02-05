abstract class Calculator {
    abstract double add(double num1, double num2);

    abstract double sub(double num1, double num2);

    abstract double multi(double num1, double num2);
}

class IntCalculator extends Calculator {

    @Override
    double add(double num1, double num2) {
        return (int) (num1 + num2);
    }

    @Override
    double sub(double num1, double num2) {
        return (int) (num1 - num2);
    }

    @Override
    double multi(double num1, double num2) {
        return (int) (num1 * num2);
    }
}

class FloatCalculator extends Calculator {

    @Override
    double add(double num1, double num2) {
        return (float) (num1 + num2);
    }

    @Override
    double sub(double num1, double num2) {
        return (float) (num1 - num2);
    }

    @Override
    double multi(double num1, double num2) {
        return (float) (num1 * num2);
    }
}

class ComplexCalculator extends Calculator {

    @Override
    double add(double num1, double num2) {
        return num1 + num2;
    }

    @Override
    double sub(double num1, double num2) {
        return num1 - num2;
    }

    @Override
    double multi(double num1, double num2) {
        return num1 * num2;
    }
}

public class Main {
    public static void main(String[] args) {
        IntCalculator intCalc = new IntCalculator();
        System.out.println("Int addition: " + intCalc.add(10, 20));
        System.out.println("Int subtraction: " + intCalc.sub(10, 20));
        System.out.println("Int multiplication: " + intCalc.multi(10, 20));

        FloatCalculator floatCalc = new FloatCalculator();
        System.out.println("Float addition: " + floatCalc.add(10.5, 20.5));
        System.out.println("Float subtraction: " + floatCalc.sub(10.5, 20.5));
        System.out.println("Float multiplication: " + floatCalc.multi(10.5, 20.5));

        ComplexCalculator complexCalc = new ComplexCalculator();
        System.out.println("Complex addition: " + complexCalc.add(10.5, 20.5));
        System.out.println("Complex subtraction: " + complexCalc.sub(10.5, 20.5));
        System.out.println("Complex multiplication: " + complexCalc.multi(10.5, 20.5));
    }
}
