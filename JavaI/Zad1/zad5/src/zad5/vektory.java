package zad5;

import java.util.Scanner;
import java.util.Vector;

public class vektory {
	private Vector<Integer>pierwszyWektor;
	private Vector<Integer>drugiWektor;
	private Scanner stdWejscie;
	
	public vektory()
	{
		this.pierwszyWektor = new Vector<Integer>();
		this.drugiWektor = new Vector<Integer>();
	}
	public void dodawanieDanych()
	{
		stdWejscie = new Scanner(System.in);
		System.out.println("Zawartosc pierwszego wektora: ");
		String buforDanych  = stdWejscie.nextLine();
		String [] poSplicie = buforDanych.split(" ");
		for(String x : poSplicie)
			pierwszyWektor.addElement(Integer.parseInt(x));
		System.out.println(pierwszyWektor.size());
		
		System.out.println("Zawartosc drugiego wektora: ");
		buforDanych  = stdWejscie.nextLine();
		poSplicie = buforDanych.split(" ");
		for(String x : poSplicie)
			drugiWektor.addElement(Integer.parseInt(x));
		System.out.println(drugiWektor.size());
		stdWejscie.close();
	}
	
}
