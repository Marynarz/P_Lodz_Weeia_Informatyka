package firstLocal;

import java.util.Collections;
import java.util.Vector;

public class test {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Location>allLocations = new Vector<Location>();
		allLocations.addElement(new Building(0,"Budynek 1"));
		allLocations.addElement(new Floor((Building)allLocations.get(0),-1,"Pietro 1"));
		allLocations.addElement(new Room((Floor)allLocations.get(1),-10,"Pokoj 5"));
		allLocations.addElement(new Room((Floor)allLocations.get(1),3,"Pokoj 3"));
		allLocations.addElement(new Room((Floor)allLocations.get(1),2,"Pokoj 2"));
		allLocations.addElement(new Floor((Building)allLocations.get(0),0,"Parter"));
		allLocations.addElement(new Room((Floor)allLocations.get(5),4,"Pokoj 5"));
		allLocations.addElement(new Room((Floor)allLocations.get(5),6,"Pokoj 3"));
		allLocations.addElement(new Room((Floor)allLocations.get(5),1,"Pokoj 2"));
		allLocations.addElement(new Room((Floor)allLocations.get(5),3,"Pokoj 5"));
		allLocations.addElement(new Room((Floor)allLocations.get(1),2,"Pokoj 3"));
		allLocations.addElement(new Room((Floor)allLocations.get(1),8,"Pokoj 2"));
		allLocations.get(0).descriptionLoc();
		
		Collections.sort(allLocations);
		allLocations.get(0).descriptionLoc();
		return;
	}
}
