package zad3;

import java.util.HashMap;
import java.util.Scanner;

public class zad3 {

	@SuppressWarnings("serial")
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner stdDat = new Scanner(System.in);
		Integer userData = new Integer(0) ;
		Integer jedn = new Integer(0);
		Integer dzies = new Integer(0);
		HashMap<Integer,String> transDic = new HashMap<Integer,String>() 
		{{
			put(1,"jeden");
			put(2,"dwa");
			put(3,"trzy");
			put(4,"cztery");
			put(5,"piec");
			put(6,"szesc");
			put(7,"siedem");
			put(8,"osiem");
			put(9,"dziewiec");
			put(0,"zero");
			put(10,"dziesiec");
			put(11,"jedenascie");
			put(12,"dwanascie");
			put(13,"trzynascie");
			put(14,"czternascie");
			put(15,"pietnascie");
			put(16,"szesnascie");
			put(17,"siedemnascie");
			put(18,"osiemnascie");
			put(19,"dziewietnascie");
			put(20,"dwadziescia");
			put(30,"trzydziesci");
			put(40,"czterdziesci");
			put(50,"pisiont");
			put(60,"szescdziesiat");
			put(70,"siedemdziesiat");
			put(80,"osiemdziesiat");
			put(90,"dziewiecdziesiat");
			put(100,"sto");
			put(200,"dwiescie");
			put(300,"trzysta");
			put(400,"czterysta");
			put(500,"piecset");
			put(600,"szescset");
			put(700,"siedemset");
			put(800,"osiemset");
			put(900,"dziewiecset");
		}};
		userData = stdDat.nextInt();
		
		//geste
		jedn = userData%10;
		userData -= jedn;
		dzies = userData%100;
		userData -=dzies;
		
		if(userData !=0)
			System.out.println(transDic.get(userData)+' '+transDic.get(dzies)+' '+transDic.get(jedn));
		else if(dzies !=0)
			System.out.println(transDic.get(dzies)+' '+transDic.get(jedn));
		else
			System.out.println(transDic.get(jedn));
		
		stdDat.close();
	}

}
