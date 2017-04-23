package Zad1;
import java.util.Scanner;

import Zad1.Silnik;

public class Zad1 {

	public static void main(String[] args) {
		Silnik s1 = new Silnik();
		Boolean gra = true;
		Boolean jeszczeRaz = true;
		Scanner stdWejscie;
		while(jeszczeRaz)
		{
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
					gra = true;
					System.out.println("Jeszcze raz? T/N");
					stdWejscie = new Scanner(System.in);
					stdWejscie.close();
					char odpowiedz = stdWejscie.nextLine().charAt(0);
					if(odpowiedz == 'N' || odpowiedz == 'n')
						jeszczeRaz = false;
					else if(odpowiedz=='T' || odpowiedz =='t')
						System.out.println("Let's play a game!");
					else
					{
						System.out.println("BLAD!");
						jeszczeRaz = false;
					}
		}

		
		return;
	}

}
