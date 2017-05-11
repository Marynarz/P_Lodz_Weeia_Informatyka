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

}
