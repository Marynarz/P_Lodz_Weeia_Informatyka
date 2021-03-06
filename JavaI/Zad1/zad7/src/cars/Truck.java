package cars;

public class Truck extends Car {
	private double weight;
	
	public Truck(int sped, double pri, String col, double wei){
		super(sped,pri,col);
		this.setWeight(wei);
	}
	public void setWeight(double wei){
		this.weight = wei;
	}
	public double getWeight(){
		return this.weight;
	}
	public double getSalePrice(){
		if(this.weight > 3000)
			return (this.price - (this.price/10));
		else
			return this.price;
	}
}
