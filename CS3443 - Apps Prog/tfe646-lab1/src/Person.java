/**
 * This class represents a Person object
 * which contains a name string, age int, and a toString() method
 * 
 * @author Daniel Ferrer-Sosa (tfe646)
 * 
 */
public class Person {
	// class attributes
	private String name; // string representing Person's name
	private int age; // int representing Person's age
	
	// default constructor
	public Person() {}
	
	// constructor given param values
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	// getters and setters
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getAge() {
		return age;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	
	// return Person obj in formatted string
	public String toString() {
		return String.format("%s(%d)", name, age); // return formatted string containing Person's information
	}
}