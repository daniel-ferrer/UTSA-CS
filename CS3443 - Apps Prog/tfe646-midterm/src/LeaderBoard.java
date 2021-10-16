import java.util.ArrayList;

/**
 * This class represents a LeaderBoard object and contains a LeaderBoard's ArrayList of names as strings
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */

public class LeaderBoard {
	// class attributes
	ArrayList<String> names;
	
	//default constructor
	public LeaderBoard() { 
		names = new ArrayList<String>(); // init ArrayList to store names
	}
	
	// prints numbered list of names currently stored
	public String toString() {
		String str = "";
		
		for(int i = 0; i < names.size(); i++) {
			str += i + 1 + " - " + names.get(i) + "\n";
		}
		
		return str;
	}
	
	// getter, setter, and adder
	public ArrayList<String> getNames() {
		return names;
	}
	
	public void setNames(ArrayList<String> names) {
		this.names = names;
	}
	
	public void addNames(String name) {
		names.add(name);
	}

}
