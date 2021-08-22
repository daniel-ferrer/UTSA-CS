
public class Person {
	// class attributes
	private String name;
	private int age;
	
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
		return String.format("%s(%d) as:", name, age);
	}
}