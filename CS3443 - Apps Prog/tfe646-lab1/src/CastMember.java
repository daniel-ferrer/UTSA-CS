/**
 * This class represents a CastMember object which extends the Person class
 * which contains a roleCount int, Role array, and Role objects and their methods
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 * 
 */
public class CastMember extends Person {
	// class attributes
	private int roleCount;
	private Role roles[];
	private int cnt; // count integer to keep track of array pos
	private int totRoleCount = 0; // total role count int to initialize array size
	
	// default constructor
	public CastMember() {}
	
	// constructor given param values
	public CastMember(String name, int age, int roleCount) {
		super(name, age);
		this.roleCount = roleCount;
		totRoleCount += roleCount;
		this.roles = new Role[totRoleCount];
		cnt = 0;
	}
	
	// getters and setters
	public int getRoleCount() {
		return roleCount;
	}
	
	public void setRoleCount(int roleCount) {
		this.roleCount = roleCount;
	}
	
	public Role[] getRoles() {
		return roles;
	}
	
	public void setRoles(Role[] roles) {
		this.roles = roles;
	}
	
	// adds Role object to Role array
	public void addRole(Role role) {
		if(cnt < roles.length) { // if current count of roles is less than roles.length
			roles[cnt] = role; // add Role to roles array at current pos
			cnt++; // increment count of current roles
		}
	}
	
	// returns string representation of the cast member
	public String toString() {
		String str = ""; // init empty string
		for(int i = 0; i < totRoleCount; i++) { // for total count of roles in show
			str += super.toString() + " as: \n"; // append person.toString() return value to string
			if(roles.length > 1) { // if CastMember has more than 1 role
				for(int j = 0; j < roles.length; j++) { // for each role given CastMember has
					str += " - " + roles[j].toString() + "\n"; // append the role to the list of roles of CastMember
				}
				i++; // increment i to skip redundant person print
			}
			else { // else append CastMember's only role
				str += " - " + roles[i].toString() + "\n";
			}
		}
		
		return str; // return string with appended information
		
	}

	
	
}
