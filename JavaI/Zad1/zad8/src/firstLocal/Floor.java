package firstLocal;

import java.util.Vector;

public class Floor extends Location {
	private int floorId;
	private int floorNumber;
	private String floorDesc;
	private Building buildingNumber;
	private Vector<Room>roomsAll;
	
	public Floor(Building b, int fNum, String fDesc){
		Location.locationIdIcrement();
		this.floorId = Location.locationId;
		this.setFloorNumber(fNum);
		this.setFloorDesc(fDesc);
		this.buildingNumber = b;
		this.buildingNumber.addFloor(this);
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub
		System.out.println("------");
		System.out.println("Floor: "+this.getFloorId());
		System.out.println("Pietro numer: "+this.getFloorNumber());
		System.out.println("Opis: "+this.getFloorDesc());
		System.out.println("Na pietrze znjaduje sie: ");
		for(int i=0; i<this.roomsAll.size();i++)
			this.roomsAll.get(i).descriptionLoc();
		System.out.println("------");
	}
	public void addRoom(Room r){
		roomsAll.addElement(r);
	}
	public int getRoomsNumber(){
		return roomsAll.size();
	}
	public void setFloorNumber(int fNum){
		try{
			if(fNum>0)
				this.floorNumber = fNum;
			else
				throw new WrongNumberException(fNum,this);
		}
		catch(WrongNumberException e){
			e.setProperNumber(this);
		}
	}
	public int getFloorNumber(){
		return this.floorNumber;
	}
	private void setFloorDesc(String fDsc){
		this.floorDesc = fDsc;
	}
	public String getFloorDesc(){
		return this.floorDesc;
	}
	public int getFloorId(){
		return this.floorId;
	}
}
