package cars;

public class Hatchback extends Car {
	private int year;
	private double manufacturerDiscount;
	
	public Hatchback(int sped, double pri, String col, int yea, double disco){
		new Car(sped,pri,col);
		this.setYear(yea);
		this.setManufacturerDiscount(disco);
	}
	private void setYear(int yea){
		this.year = yea;
	}
	private void setManufacturerDiscount(double disco){
		this.manufacturerDiscount = disco;
	}
	public int getYear(){
		return this.year;
	}
	public double getManufacturerDicsount(){
		return this.manufacturerDiscount;
	}
	public double getSalePrice(){
		return this.price-((this.getManufacturerDicsount() /100)*this.price);
	}

}
