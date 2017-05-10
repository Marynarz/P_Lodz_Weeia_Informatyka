package firstLocal;

public class Floor extends Location {
	private int floorId;
	private static int roomsNumber=0;
	private String floorName;
	private String floorDesc;
	private Building buildingNumber;
	
	public Floor(){
		Location.locationIdIcrement();
		this.floorId = Location.locationId;
	}
	
	public Floor(Building b){
		buildingNumber = b;
		Building.floorsNumberIncrement();
		this.floorId = Building.getFloorsNumber();
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub

	}

}
