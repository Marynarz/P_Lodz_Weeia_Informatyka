package zad2;

import java.math.BigInteger;

public class NrbVal {
	private boolean validDat;
	private BigInteger nrbBI;
	public NrbVal(String nrbNumb){
		this.nrbBI = new BigInteger(nrbNumb);
		this.valDat();
	}
	private void valDat(){
		this.nrbBI = this.nrbBI.multiply(new BigInteger("1000000")).add(new BigInteger("252100"));
		//113010170021100249900004
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
