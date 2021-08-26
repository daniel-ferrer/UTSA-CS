
public class CastMember extends Person {
	// class attributes
	private int roleCount;
	private Role roles[];
	
	// default constructor
	public CastMember() {}
	
	// constructor given param values
	public CastMember(String name, int age, int roleCount) {
		super(name, age);
		this.roleCount = roleCount;
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
	
	
	
	// return string representation of the cast member
	public String toString() {
		
		return "";
	}

	public void addRole(Role role) {
		int len = roles.length;
		Role[] temp = new Role[len + 1];
		
		for(int i = 0; i < len; i++) {
			temp[i] = this.roles[i];
		}
		temp[len] = role;
		this.roles = temp;
		
	}
	
}
