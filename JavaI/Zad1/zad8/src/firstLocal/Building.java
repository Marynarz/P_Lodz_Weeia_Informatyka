package firstLocal;

import java.util.Vector;

public class Building extends Location {
	private int buildingId;
	private int buildingNumber;
	private String buildingDesc;
	private Vector<Floor>floorsAll;
	
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
		for(int i=0; i<floorsAll.size();i++)
			this.floorsAll.get(i).descriptionLoc();
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
		floorsAll.addElement(f);
	}
	public int getFloorsNumber(){
		return floorsAll.size();
	}
	public int getBuildingId(){
		return this.buildingId;
	}

}
