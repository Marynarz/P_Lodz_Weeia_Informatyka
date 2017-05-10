package firstLocal;

public class Room extends Location {
	public int roomId;
	public String roomName;
	private Floor floorNumber;
	
	public Room(Floor f){
		this.floorNumber = f;
	}
	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub

	}

}
