package cars;

public class Car {
	protected int speed;
	protected double price;
	protected String color;
	
	public Car(){
		this.speed = 200;
		this.price = 10000;
		this.color = "Red";
	}
	public Car(int sped, double pri, String col){
		this.setColor(col);
		this.setPrice(pri);
		this.setSpeed(sped);
	}
	public void setSpeed(int sped){
		this.speed = sped;
	}
	public void setPrice(double pri){
		this.price = pri;
	}
	public void setColor(String col){
		this.color = col;
	}
	public int getSpeed(){
		return this.speed;
	}
	public double getSalePrice(){
		return this.price;
	}
	public String getColor(){
		return this.color;
	}
}
