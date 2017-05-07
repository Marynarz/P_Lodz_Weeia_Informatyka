package cars;

public class Autoshop {
	private Truck pickup;
	private Hatchback haczbak;
	private Sedan sedanik;
	
	public Autoshop(){
		this.pickup = new Truck(250,105000,"Brown",3400);
		this.haczbak = new Hatchback(150,88000,"Pink",2017,12.6);
		this.sedanik = new Sedan(184,550000,"Black",4999);
	}
	public void getCatalogue(){
		System.out.println("Truck: Vmax: "+this.pickup.getSpeed()+" Kolor: "+this.pickup.getColor()+" Waga: "+this.pickup.getWeight()+" Cena: "+this.pickup.getSalePrice());
		System.out.println("HatchBack: Vmax: "+this.haczbak.getSpeed()+" Kolor: "+this.haczbak.getColor()+"Rok: "+this.haczbak.getYear()+" Cena: "+this.haczbak.getSalePrice());
		System.out.println("Sedan: Vmax: "+this.sedanik.getSpeed()+" Kolor: "+this.sedanik.getColor()+" Dlugosc: "+this.sedanik.getLenght()+" Cena: "+this.sedanik.getSalePrice());
	}
}
