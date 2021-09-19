/**
 * This class represents an Avenger object which extends the Person class
 * and contains an Avenger's alias, gender, height, and current location as strings, their weight as a double, 
 * and a boolean representing if they have special abilities or not
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Avenger extends Person {
	// class attributes
	private String alias;
	private String gender;
	private String heightFt;
	private String heightIn;
	private double weight;
	private String currLocation;
	private boolean hasSpecialAbilities;
	
	// default constructor
	public Avenger() {}
	
	// constructor given param values
	public Avenger(String name, String alias, String gender, String heightFt, String heightIn, double weight, boolean hasSpecialAbilities, String currLocation) {
		super(name);
		this.alias = alias;
		this.gender = gender;
		this.heightFt = heightFt;
		this.heightIn = heightIn;
		this.weight = weight;
		this.currLocation = currLocation;
		this.hasSpecialAbilities = hasSpecialAbilities;
	}
	
	// getters and setters
	public String getAlias() {
		return alias;
	}
	
	public void setAlias(String alias) {
		this.alias = alias;
	}
	
	public String getGender() {
		return gender;
	}
	
	public void setGender(String gender) {
		this.gender = gender;
	}
	
	public String getHeightFt() {
		return heightFt;
	}
	
	public void setHeightFt(String heightFt) {
		this.heightFt = heightFt;
	}
	
	public String getHeightIn() {
		return heightIn;
	}
	
	public void setHeightIn(String heightIn) {
		this.heightIn = heightIn;
	}
	
	public double getWeight() {
		return weight;
	}
	
	public void setWeight(double weight) {
		this.weight = weight;
	}
	
	public String getCurrLocation() {
		return currLocation;
	}
	
	public void setCurrLocation(String currLocation) {
		this.currLocation = currLocation;
	}
	
	public boolean getHasSpecialAbilities() {
		return hasSpecialAbilities;
	}
	
	public void setHasSpecialAbilities(boolean hasSpecialAbilities) {
		this.hasSpecialAbilities = hasSpecialAbilities;
	}
	
	// returns a String representation of the Avenger
	public String toString() {
		String str = "";
		str += " - " + super.toString() + " (" + alias + ")\n";
		
		if(hasSpecialAbilities) {
			str += "   Special Abilities: Yes\n";
		}
		else {
			str += "   Special Abilities: No\n";
		}
		
		
		str += "   " + gender + ", " + heightFt + "'" + heightIn + "\", "  + weight + "lbs\n";
		str += "   Current location: " + currLocation + "\n\n"; 
		
		return str;
	}
	
}
