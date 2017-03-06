package Silnik;
import java.util.Random;


public class Silnik {
	private int magicznaLiczba;
	public Silnik()
	{
		Random gene = new Random();
		this.magicznaLiczba = gene.nextInt(100);
		
		System.out.println("Magiczna liczba: "+magicznaLiczba);
	}

}
