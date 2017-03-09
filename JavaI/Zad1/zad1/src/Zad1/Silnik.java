package Zad1;
import java.util.Random;
import java.util.Scanner;


public class Silnik {
	private int magicznaLiczba;
	private Scanner stdWejscie;

	public Silnik()
	{
		this.generatorLiczby();
		
		System.out.println("Magiczna liczba: "+magicznaLiczba);
	}
	private void generatorLiczby()
	{
				Random gene = new Random();
		this.magicznaLiczba = gene.nextInt(100);
	}
	public coSieDzieje Zgaduj()
	{
		stdWejscie = new Scanner(System.in);
		System.out.println("Podaj liczbe: ");
		int odpowiedz = stdWejscie.nextInt();
		
		if(odpowiedz > magicznaLiczba)
			return coSieDzieje.zaDuzo;
		else if(odpowiedz < magicznaLiczba)
			return coSieDzieje.zaMalo;
		else
			return coSieDzieje.ok;
	}
	public enum coSieDzieje{
		zaMalo,
		ok,
		zaDuzo;
	}
}
