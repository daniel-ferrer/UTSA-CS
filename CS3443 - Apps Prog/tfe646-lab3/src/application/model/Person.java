/**
 * 
 */
package application.model;

/**
  * This class represents a Person object
 * and contains a Person's name as a string
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */

public class Person {
	//class attributes
	private String name;
	
	// default constructor
	public Person() {}
	
	// constructor given param values
	public Person(String name) {
		this.name = name;
	}
	
	// getters and setters
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String toString() {
		String str = name;
		
		return str;
	}
	
	
}
