package firstLocal;

import java.util.Vector;

public class Floor extends Location {
	private int floorId;
	private static int roomsNumber=0;
	private int floorNumber;
	private String floorDesc;
	private Building buildingNumber;
	private Vector<Room>roomsAll;
	
	public Floor(Building b){
		Location.locationIdIcrement();
		this.floorId = Location.locationId;
		b.addFloor(this);
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub

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

}
