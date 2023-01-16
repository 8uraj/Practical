package PRACTICLE;
import java.util.Scanner;

public class AdditionSuraj {

	public static void main(String[] args) {
		try (Scanner obj = new Scanner(System.in)) {
			System.out.println("Enter First number: ");
			float a= obj.nextFloat();
		
			System.out.println("Enter Second Number: ");
			float b=obj.nextFloat();

			System.out.println("Addition Is: ");
			float sum=a+b;

			System.out.println(a+b);
		}
	
	}
}
								
