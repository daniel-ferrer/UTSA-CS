/**
 * 
 */
package application.model;

import java.util.ArrayList;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Scene {
	// class attributes
	private int id;
	private String title;
	private ArrayList<Role> roles;
	
	//default contructor
	public Scene() { }
	
	// constructor given @param values
	public Scene(int id, String title) {
		this.id = id;
		this.title = title;
		this.roles = new ArrayList<Role>();
	}
	
	// getters and setters
	public int getID() {
		return id;
	}
	
	public void setID(int id) {
		this.id = id;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}

	public ArrayList<Role> getRoles() {
		return roles;
	}
	
	public void setRoles(ArrayList<Role> roles) {
		this.roles = roles;
	}
}
