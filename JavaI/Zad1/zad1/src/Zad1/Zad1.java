package Zad1;
import Zad1.Silnik;

public class Zad1 {

	public static void main(String[] args) {
		Silnik s1 = new Silnik();
		Boolean gra = true;
		while(gra)
		{
			Silnik.coSieDzieje wynik = s1.Zgaduj();
			if(wynik == Silnik.coSieDzieje.ok)
			{
				System.out.println("Jest ok!");
				gra = false;
			}
			else if (wynik == Silnik.coSieDzieje.zaDuzo)
			{
				System.out.println("Za duzo!");
			}
			else if (wynik == Silnik.coSieDzieje.zaMalo)
			{
				System.out.println("Za malo!");
			}
		}
		s1.Statystyki();
		
		return;
	}

}
