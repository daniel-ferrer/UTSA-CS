import java.io.*;
import java.util.ArrayList;

/**
 * This class represents a Team object which extends the Avenger class
 * and contains a Team's name as a string and an ArrayList of Avengers
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Team extends Avenger {
	// class attributes
	private String name;
	private ArrayList<Avenger> avengers;
	
	// default constructor
	public Team() {}
	
	// constructor given param values
	public Team(String name) {
		this.name = name;
		this.avengers = new ArrayList<Avenger>();
	}
	
	//getters and setters
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public ArrayList<Avenger> getAvengers() {
		return avengers;
	}
	
	public void setAvengers(ArrayList<Avenger> avengers) {
		this.avengers = avengers;
	}
	
	// adds Avengers from .csv file to a Team
	public void loadAvengers(String fname) throws FileNotFoundException {
		String fpath = "./data/" + fname;
		String line = "";
		String delim = ",";
		
		try {
			// create buffered char input stream using .csv file
			BufferedReader reader = new BufferedReader(new FileReader(fpath)); 
			while((line = reader.readLine()) != null) {
				
				// separate qualities of each avenger into array
				String[] temp = line.split(delim); 
				
				// declare avenger, add their qualities, and add them to an ArrayList
				Avenger avenger = new Avenger(); 
				avenger.setName(temp[0]);
				avenger.setAlias(temp[1]);
				avenger.setGender(temp[2]);
				avenger.setHeightFt(temp[3]);
				avenger.setHeightIn(temp[4]);
				avenger.setWeight(Double.parseDouble(temp[5]));
				if(temp[6].equalsIgnoreCase("T")) {
					avenger.setHasSpecialAbilities(true);
				}
				else {
					avenger.setHasSpecialAbilities(false);
				}

				avenger.setCurrLocation(temp[7]);
				addAvenger(avenger);
			}		
			reader.close();
			
		} catch(IOException e) {
			System.out.println("Error loading Avengers");
			e.printStackTrace();
		}			
	}
	
	// adds Avenger to avengers list
	public void addAvenger(Avenger avenger) {
		avengers.add(avenger);
	}
	
	public String toString() {
		String str = "Team " + name + ":\n";
		for(int i = 0; i < avengers.size(); i++) {
			str += avengers.get(i);
		}
		
		return str;
	}
}
