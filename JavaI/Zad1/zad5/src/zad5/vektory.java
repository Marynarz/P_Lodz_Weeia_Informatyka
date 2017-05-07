package zad5;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class vektory {
	private Vector<Integer>pierwszyWektor;
	private Vector<Integer>drugiWektor;
	private Vector<Integer>wyjsciowyWektor;
	private Scanner stdWejscie;
	private String buforDanych;
	private String [] poSplicie;
	private FileWriter daneDoZapisu;
	
	public vektory()
	{
		this.pierwszyWektor = new Vector<Integer>();
		this.drugiWektor = new Vector<Integer>();
		this.wyjsciowyWektor = new Vector<Integer>();
	}
	public void dodawanieDanych()
	{
		stdWejscie = new Scanner(System.in);
		this.dodawanieW1();
		this.dodawanieW2();

		//stdWejscie.close();
		this.sumowanieDanych();
	}
	private void dodawanieW1()
	{
		System.out.println("Zawartosc pierwszego wektora: ");
		buforDanych  = stdWejscie.nextLine();
		poSplicie = buforDanych.split(" ");
		for(String x : poSplicie)
			pierwszyWektor.addElement(Integer.parseInt(x));
	}
	private void dodawanieW2()
	{
		System.out.println("Zawartosc drugiego wektora: ");
		buforDanych  = stdWejscie.nextLine();
		poSplicie = buforDanych.split(" ");
		for(String x : poSplicie)
			drugiWektor.addElement(Integer.parseInt(x));
	}
	private void sumowanieDanych()
	{
		try{
			if(pierwszyWektor.size() != drugiWektor.size())
				throw new DifferentVectorSizeException(pierwszyWektor.size(),drugiWektor.size());
			
			for(int i=0; i<pierwszyWektor.size();i++)
				wyjsciowyWektor.addElement(pierwszyWektor.get(i) + drugiWektor.get(i));
			this.zapisDanych();
			System.out.println(wyjsciowyWektor.toString());
			
		}
		catch(DifferentVectorSizeException e){
			if(pierwszyWektor.size()<drugiWektor.size()){
				System.out.println("Dopelnij pierwszy wektor o "+(drugiWektor.size()-pierwszyWektor.size())+" miejsc");
				this.dodawanieW1();
			}
			else{
				System.out.println("Dopelnij drugi wektor o "+(pierwszyWektor.size()-drugiWektor.size())+" miejsc");
				this.dodawanieW2();
			}
			
			if(pierwszyWektor.size() == drugiWektor.size())
				this.sumowanieDanych();
			else
				System.out.println("Nie chcesz wspolpracowac to nie");
		}
		catch(IOException e){
			System.out.println(e);
		}
		
	}
	private void zapisDanych() throws IOException{
		String plik = "daneZad5.txt";
		daneDoZapisu = new FileWriter(plik);
		daneDoZapisu.write(wyjsciowyWektor.toString());
		daneDoZapisu.close();
	}
	
}