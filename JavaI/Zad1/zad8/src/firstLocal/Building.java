package firstLocal;

import java.util.Vector;

public class Building extends Location {
	private int buildingId;
	private int buildingNumber;
	private String buildingDesc;
	private Vector<Floor>floorsAll;
	
	public Building(){
		Location.locationIdIcrement();
		this.buildingId = Location.locationId;
		floorsAll = new Vector<Floor>();
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub
		System.out.println("Building: "+buildingId);
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

}
