package zad2;

public class zad2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(args[0]);
		try
		{
			int poczatek = Integer.parseInt(args[1]);
			int koniec = Integer.parseInt(args[2]);
			String s = args[0];
			System.out.println(s.substring(poczatek, koniec));
		}
		catch(NumberFormatException e)
		{
			System.out.println("Zly format liczby");
		}
		catch(StringIndexOutOfBoundsException e)
		{
			System.out.println("Zly zakres");
		}
		return;

	}

}
