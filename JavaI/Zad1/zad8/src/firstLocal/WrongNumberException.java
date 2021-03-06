package firstLocal;

import java.util.Scanner;

public class WrongNumberException extends Exception {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	public WrongNumberException(int bNum, Building b){
		System.out.println("WRONG_NUMBER_EXCEPTION: Wrong Building number: "+bNum);
	}
	public WrongNumberException(int bNum, Floor f){
		System.out.println("WRONG_NUMBER_EXCEPTION: Wrong Floor number: "+bNum);
	}
	public WrongNumberException(int bNum, Room r){
		System.out.println("WRONG_BUILDING_EXCEPTION: Wrong Room number: "+bNum);
	}
	public void setProperNumber(Building b){
		System.out.println("Do you want set proper buildingNumber? (Y/N); ");
		Scanner stdWejscie = new Scanner(System.in);
		char answer = stdWejscie.nextLine().charAt(0);
		if(answer == 'Y' || answer == 'y'){
			System.out.println("Write number grater than 0: ");
			int bNum = stdWejscie.nextInt();
			b.setBuildingNumber(bNum);
		}
		else{
			System.out.println("Foch z przytupem i melodyjka!");
		}
		//stdWejscie.close();
	}
	public void setProperNumber(Floor f){
		System.out.println("Do you want set proper floorNumber? (Y/N); ");
		Scanner stdWejscie = new Scanner(System.in);
		char answer = stdWejscie.nextLine().charAt(0);
		if(answer == 'Y' || answer == 'y'){
			System.out.println("Write number grater than 0: ");
			int bNum = stdWejscie.nextInt();
			f.setFloorNumber(bNum);
		}
		else{
			System.out.println("Foch z przytupem i melodyjka!");
		}
		//stdWejscie.close();
	}
	public void setProperNumber(Room r){
		System.out.println("Do you want set proper roomNumber? (Y/N); ");
		Scanner stdWejscie = new Scanner(System.in);
		char answer = stdWejscie.nextLine().charAt(0);
		if(answer == 'Y' || answer == 'y'){
			System.out.println("Write number grater than 0: ");
			int bNum = stdWejscie.nextInt();
			r.setRoomNumber(bNum);
		}
		else{
			System.out.println("Foch z przytupem i melodyjka!");
		}
		//stdWejscie.close();
	}
}
