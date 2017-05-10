package firstLocal;

public class Building extends Location {
	private int buildingId;
	private String buildingName;
	private String buildingDesc;
	private static int floorsNumber=0;
	
	public Building(){
		Location.locationIdIcrement();
		this.buildingId = Location.locationId;
	}

	@Override
	protected void descriptionLoc() {
		// TODO Auto-generated method stub
		System.out.println("Building: "+buildingId);
	}
	public static void floorsNumberIncrement(){
		floorsNumber++;
	}
	public static int getFloorsNumber(){
		return floorsNumber;
	}

}
