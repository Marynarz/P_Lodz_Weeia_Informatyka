package zad3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Zad3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double a,b,c,delta,x0,x1;
		
		try{
			Scanner stdWejscie = new Scanner(System.in);
			System.out.println("Wspolczynnik a:");
			a=stdWejscie.nextDouble();
			System.out.println("Wspolczynnik b:");
			b=stdWejscie.nextDouble();
			System.out.println("Wspolczynnik c:");
			c=stdWejscie.nextDouble();
			stdWejscie.close();
			
		}
		catch(InputMismatchException e){
			System.out.println("Zly numer");
			return;
		}
		
		delta = Math.pow(b,2) - 4 * a *c;
		System.out.println(delta);
		
		if(delta >0)
		{
			x0 = (-b - Math.sqrt(delta)) / (2 * a);
			x1 = (-b + Math.sqrt(delta)) / (2 * a);
			System.out.println("Dwa miejsca zerowe X0: "+x0+" i X0: "+x1);
		}
		else if(delta ==0)
		{
			x0 = (-b) / (2 * a);
			System.out.println("Jedno miejsce zerowe. X0: "+x0);
		}
		else
			System.out.println("Brak miejsc zerowych");
		
		return;
	}

}
