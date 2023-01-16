package PRACTICLE;
import java.util.Scanner;


public class CompareINT {

public static void main(String[] args) 
		{
			Scanner obj = new Scanner(System.in);
			
			System.out.println("Enter 4 numbers:");
			int a=obj.nextInt();
			int b=obj.nextInt();
			int c=obj.nextInt();
			int d=obj.nextInt();	

			if ((a==b) && (b==c) && (c==d) && (a==d)) {
				System.out.println("All INTEGERS are equal");
			}
			else {
				System.out.println("All INTEGERS are not equal");
			}
			
		}

	}
