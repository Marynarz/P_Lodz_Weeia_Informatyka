package zad6;

public class zad6 {

	public static void main(String[] args) {
		SavingsAccount konto1 = new SavingsAccount(3000);
		System.out.println("Wartosc poczatkowa: "+konto1.balanceSavings());
		
		//wplacanie
		konto1.depositSavings(2000);
		System.out.println("Wplacenie 2000: "+konto1.balanceSavings());
		
		//policzenie i dodanie raty
		konto1.calculateMonthlyInterst();
		System.out.println("Po miesiacu: "+konto1.balanceSavings());
		
		//zmiana rocznego oprocentowania
		SavingsAccount.modifyInterstRate(6.74);
		
		//policzmy jeszcze raz
		konto1.calculateMonthlyInterst();
		System.out.println("Kolejny miesiac po zmianie raty: "+konto1.balanceSavings());
		
		//wyplata
		konto1.withdrawSavings(342.7);
		System.out.println("Wyplacenie 342.7: "+konto1.balanceSavings());
		
		return;
	}

}
