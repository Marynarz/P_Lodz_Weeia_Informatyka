package zad6;

public class SavingsAccount {
	static double annualInterstRate = 3.5;
	private double savingsBalance;
	
	public SavingsAccount(double savings){
		this.depositSavings(savings);
	}
	public void depositSavings(double savings){
		this.savingsBalance += savings;
	}
	public double balanceSavings(){
		return savingsBalance;
	}
	public void withdrawSavings(double savings){
		this.savingsBalance -=savings;
	}
	public void calculateMonthlyInterst(){
		double interst = (annualInterstRate*this.savingsBalance)/12;
		System.out.println("Miesieczny wynik: "+interst);
		System.out.println("Oprocentowanie roczne: "+ annualInterstRate);
		this.savingsBalance +=interst;
	}
	static void modifyInterstRate(double newRate){
		annualInterstRate = newRate;
	}
}
