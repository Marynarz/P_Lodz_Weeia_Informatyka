package Zad1;
import java.util.Random;
import java.util.Scanner;


public class Silnik {
	private int magicznaLiczba;
	private Scanner stdWejscie;
	private int licznikUzycia;

	public Silnik()
	{
		this.resetGame();
	}
	private void generatorLiczby()
	{
				Random gene = new Random();
		this.magicznaLiczba = gene.nextInt(100);
	}
	public coSieDzieje Zgaduj()
	{
		
		licznikUzycia++;
		stdWejscie = new Scanner(System.in);
		System.out.println("Podaj liczbe: ");
		int odpowiedz = stdWejscie.nextInt();
		//stdWejscie.close();
		
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
	public void Statystyki()
	{
		System.out.println("Magiczna liczba bylo: "+magicznaLiczba);
		System.out.println("Grales "+licznikUzycia+" razy");
		this.resetGame();
	}
	private void resetGame()
	{
		this.generatorLiczby();
		this.licznikUzycia = 0;
		System.out.println("Magiczna liczba: "+magicznaLiczba);
	}
}
