/**
 * 
 */
package application.model;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Role {
	// class attributes
	private String name;
	
	// default constructor
	public Role() { }
	
	// constructor given param values
	public Role(String name) {
		this.name = name;
	}
	
	// getters and setters
	public String getName() {
		return name;
	}
		
	public void setName(String name) {
		this.name = name;
	}
}
