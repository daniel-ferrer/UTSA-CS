/**
 * 
 */
package application.model;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * This class represents an Avenger object which extends the Person class
 * and contains an Avenger's alias and current location as strings
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */

public class Avenger extends Person {
	// class attributes
	private String alias;
	private String currLocation;

	
	// default constructor
	public Avenger() {}
	
	// constructor given param values
	public Avenger(String name, String alias, String currLocation) {
		super(name);
		this.alias = alias;
		this.currLocation = currLocation;
	}
	
	public Avenger loadData(String avengerAlias) throws FileNotFoundException {
		String fpath = "./data/data.csv";
		String line = "";
		String delim = ",";
		
		Avenger avenger = new Avenger();
		
		try {
			// create buffered char input stream using .csv file
			BufferedReader reader = new BufferedReader(new FileReader(fpath)); 
			while((line = reader.readLine()) != null) {
				
				// separate qualities of each avenger into array
				String[] temp = line.split(delim); 
				
				// declare avenger, add their qualities, and add them to an ArrayList
				 
				avenger.setName(temp[0]);
				avenger.setAlias(temp[1]);
				avenger.setCurrLocation(temp[7]);
				
				if(avenger.getAlias() == avengerAlias) {
					reader.close();
					return avenger;				
				}			
			}		
			
			reader.close();
			
		} catch(IOException e) {
			System.out.println("Error loading file\n");
			e.printStackTrace();
		}
		
		return avenger;
	}

	
	// returns a String representation of the Avenger
	public String toString() {
		String str = "";
		
		str += " - " + super.toString() + " (" + alias + ")\n";
		str += "   Current location: " + currLocation + "\n\n"; 
		
		return str;
	}
	

	// getters and setters
		public String getAlias() {
			return alias;
		}
		
		public void setAlias(String alias) {
			this.alias = alias;
		}
		
		public String getCurrLocation() {
			return currLocation;
		}
		
		public void setCurrLocation(String currLocation) {
			this.currLocation = currLocation;
		}
	
	
}
