package firstLocal;

public class Room extends Location {
	private int roomId;
	private int roomNumber;
	private String roomDesc;
	private Floor floorNumber;
	
	public Room(Floor f){
		Location.locationIdIcrement();
		this.roomId = Location.locationId;
		this.floorNumber = f;
		f.addRoom(this);
	}
	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub
		System.out.println("------");
		System.out.println("Room: "+this.getRoomId());
		System.out.println("Pokoj numer: "+this.getRoomNumber());
		System.out.println("Opis: "+this.getRoomDesc());
		System.out.println("------");
	}
	public int getRoomNumber(){
		return this.roomNumber;
	}
	public void setRoomNumber(int rNum){
		try{
			if(rNum>0)
				this.roomNumber = rNum;
			else
				throw new WrongNumberException(rNum,this);
		}
		catch(WrongNumberException e){
			e.setProperNumber(this);
		}
	}
	public int getRoomId(){
		return this.roomId;
	}
	private void setRoomDesc(String rDsc){
		this.roomDesc = rDsc;
	}
	public String getRoomDesc(){
		return this.roomDesc;
	}

}
