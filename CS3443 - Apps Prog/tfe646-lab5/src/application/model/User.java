/**
 * 
 */
package application.model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */

public class User {
	// class attributes
	private String username;
	private String password;
	private String name;
	private ArrayList<Role> roles;
	
	// default constructor
	public User() { }
	
	// constructor given @param values
	public User(String username, String password, String name) {
		this.username = username;
		this.password = password;
		this.name = name;
		this.roles = new ArrayList<Role>();
	}
	
	// validates if given username and password exist in file
	public User validate(String username, String password) {
		String fpath = "./data/users.csv";
		String line = "";
		String delim = ",";
		
		User user = new User();
		boolean isValid = false;
		
		try {
			BufferedReader reader = new BufferedReader(new FileReader(fpath));
			while((line = reader.readLine()) != null) {
				
				if(isValid) { break; } // effeciancy!... maybe
				
				String[] _user = line.split(delim);
				int len = 6 -_user.length; // get number of roles to read for user

				if(Objects.equals(username, _user[0])) {
					if(Objects.equals(password, _user[1])) {
						isValid = true;
						user = new User(_user[0], _user[1], _user[2]);
						
						// add user's roles if any
						if(len <= 2) {
							Role role = new Role(_user[3]);
							user.addRole(role);
							if(len <= 1) {
								Role role2 = new Role(_user[4]);
								user.addRole(role2);
							}
						}						
					}
				}											
			}
			reader.close();
			
		} catch(IOException e) { e.printStackTrace(); }
		
		if (isValid)
			return user;
		else return null;
	}
	
	// adds Role to user's role list
	public void addRole(Role role) {
		roles.add(role);
	}
	
	// getters and setters
	public String getUsername() {
		return username;
	}
	
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	
	public void setPassword(String password) {
		this.password = password;
	}
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public ArrayList<Role> getRoles() {
		return roles;
	}
	
	public void setRoles(ArrayList<Role> roles) {
		this.roles = roles;
	}
}