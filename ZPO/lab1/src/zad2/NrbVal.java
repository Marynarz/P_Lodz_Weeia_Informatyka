package zad2;

import java.math.BigInteger;
	/**
	 * Klasa NrbVal - walidacja numeru NRB
	 * Lab1 - zad2
	 * @author Wojciech Niedzielski
	 */
public class NrbVal {

	private boolean validDat;
	private BigInteger nrbBI;
	public NrbVal(String nrbNumb){
		/**
		 * Konstruktor przypisuje numer konta do zmiennej nrbBI, a potem sprawdza poprawność numeru konta
		 */
		this.nrbBI = new BigInteger(nrbNumb);
		this.valDat();
	}
	private void valDat(){
		/**
		 * Sprawdzanie poprawnosci numeru konta
		 * dodanie do konca numeru kodu panstwa (PL - 2521)
		 * przesuniecie pierwszych dwoch cyfr na koniec
		 * sprawdzenie podzielnosci przez 97, jesli modulo rowne 1 to numer jest dobry.
		 */
		this.nrbBI = this.nrbBI.multiply(new BigInteger("1000000")).add(new BigInteger("252100"));
		this.nrbBI = this.nrbBI.remainder(new BigInteger("1000000000000000000000000000000")).add(this.nrbBI.divide(new BigInteger("1000000000000000000000000000000")));
		this.validDat = this.nrbBI.mod(new BigInteger("97")).intValue() == 1 ? true : false;
	}
	public BigInteger getBi(){
		return this.nrbBI;
	}
	public boolean getVal(){
		return this.validDat;
	}
}
