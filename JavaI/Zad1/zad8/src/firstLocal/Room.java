package firstLocal;

public class Room extends Location {
	private int roomId;
	private int roomNumber;
	private Floor floorNumber;
	
	public Room(Floor f){
		f.addRoom(this);
	}
	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub

	}
	public int getRoomNumber(){
		return this.roomNumber;
	}

}
