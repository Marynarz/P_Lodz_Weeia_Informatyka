package firstLocal;

import java.util.Collections;
import java.util.List;
import java.util.Vector;

public class Building extends Location {
	private int buildingId;
	private int buildingNumber;
	private String buildingDesc;
	private List<Floor>floorsAll;
	
	public Building(int bNum, String bDsc){
		Location.locationIdIcrement();
		this.buildingId = Location.locationId;
		this.setBuildingNumber(bNum);
		this.setBuildingDesc(bDsc);
		floorsAll = new Vector<Floor>();
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub
		
		System.out.println("------");
		System.out.println("Building: "+this.getBuildingId());
		System.out.println("Budynek numer: "+this.buildingNumber);
		System.out.println("Opis: "+this.buildingDesc);
		System.out.println("W budynku znjaduje sie: ");
		if(floorsAll.size()==0)
			System.out.println("Nic");
		else{
			for(int i=0; i<floorsAll.size();i++)
				this.floorsAll.get(i).descriptionLoc();	
		}

		System.out.println("------");
	}
	public void setBuildingNumber(int bNum){
		try{
			if(bNum >0)
				this.buildingNumber=bNum;
			else
				throw new WrongNumberException(bNum,this);
		}
		catch(WrongNumberException e){
			e.setProperNumber(this);
		}
	}
	public int getBuldingNumber(){
		return this.buildingNumber;
	}
	public void setBuildingDesc(String bDesc){
		this.buildingDesc = bDesc;
	}
	public String getBuildingDesc(){
		return this.buildingDesc;
	}
	public void addFloor(Floor f){
		floorsAll.add(f);
	}
	public Integer getFloorsNumber(){
		return (Integer) floorsAll.size();
	}
	public int getBuildingId(){
		return this.buildingId;
	}

	@Override
	public int compareTo(Location o) {
		try{
			Collections.sort(this.floorsAll);
			Building r1 = (Building) o;
			return this.getFloorsNumber().compareTo(r1.getFloorsNumber());
		}
		catch(ClassCastException e) {
			System.out.println("Blad rzutowania return 0");
			return 0;
		}
	}

}
