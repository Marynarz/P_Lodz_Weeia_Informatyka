package zad5;

public class DifferentVectorSizeException extends Exception {

	private static final long serialVersionUID = 1L;

	public DifferentVectorSizeException(int s1, int s2)
	{
		System.out.println("[VECTOR_EXCEPTION]Rozna wielkosc wektorow! Wektor pierwszy: "+s1+" Wektor drugi: "+s2);
	}
}
