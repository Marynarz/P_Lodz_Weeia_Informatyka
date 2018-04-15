package zad1;

public class calc {
	
	private int numb;
	public calc(String Numb){
		this.numb = Integer.parseInt(Numb, 2);
	}
	public String getDec(){
		return Integer.toString(this.numb);
	}
	public String getHex(){
		return Integer.toHexString(this.numb);
	}
	public String getOct(){
		return Integer.toOctalString(this.numb);
	}
	public String getBin(){
		return Integer.toBinaryString(this.numb);
	}
	public String getThr(){
		int tempN = this.numb;
		String tempS = "";
		while(tempN!=0){
			tempS += Integer.toString(tempN%3);
			tempN /=3;
		}
		tempS = new StringBuffer(tempS).reverse().toString();
		tempN = Integer.parseInt(tempS);
		return Integer.toString(tempN); //todo
	}
}
