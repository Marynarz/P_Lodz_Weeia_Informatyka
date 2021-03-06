package zad3;

import java.io.BufferedWriter;

import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Zad3 {

	public static void main(String[] args) throws IOException{
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
		
		Writer daneDoZapisu = new BufferedWriter(new FileWriter(args[0],true));	
		daneDoZapisu.append("a: "+a+", b: "+b+", c: "+c+", DELTA: "+delta+"\n");
		
		if(delta >0)
		{
			x0 = (-b - Math.sqrt(delta)) / (2 * a);
			x1 = (-b + Math.sqrt(delta)) / (2 * a);
			System.out.println("Dwa miejsca zerowe X0: "+x0+" i X0: "+x1);
			daneDoZapisu.append("x0: "+x0+", x1: "+x1+"\n");
		}
		else if(delta ==0)
		{
			x0 = (-b) / (2 * a);
			System.out.println("Jedno miejsce zerowe. X0: "+x0);
			daneDoZapisu.append("x0: "+x0+"\n");
		}
		else
		{
			System.out.println("Brak miejsc zerowych");
			daneDoZapisu.append("BRAK\n");
		}
		daneDoZapisu.append("---\n");
		
		daneDoZapisu.close();

		
		return;
	}

}
