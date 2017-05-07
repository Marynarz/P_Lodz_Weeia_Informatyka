package cars;

public class Sedan extends Car{
	private double lenght;
	
	public Sedan(int sped, double pri, String col, double len){
		new Car(sped,pri,col);	
		this.setLenght(len);
	}
	private void setLenght(double len){
		this.lenght = len;
	}
	public double getLenght(){
		return this.lenght;
	}
	public double getSalePrice(){
		if(this.getLenght() > 4500)
			return (this.price - (this.price/10));
		else
			return this.price;
	}

}
