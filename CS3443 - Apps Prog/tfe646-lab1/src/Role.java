/**
 * This class represents a Role object
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 * 
 */
public class Role extends Person{

	// default constructor
	public Role() {}
	
	// constructor given param values
	public Role(String name, int age) {
		super(name, age); // call upon Person constructor to create a new Role
	}
}
