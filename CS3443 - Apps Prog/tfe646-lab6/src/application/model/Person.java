/**
 * 
 */
package application.model;

import javafx.scene.image.Image;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Person {
	// class attributes
	private String name;
	private String heightFt;
	private String heightIn;
	private String weight;
	private String img;
	


	// default constructor
	public Person() { }
	
	// constructor given @param values
	public Person(String name, String heightFt, String heightIn, String weight) {
		this.name = name;
		this.heightFt = heightFt;
		this.heightIn = heightIn;
		this.weight = weight;
	}
	

	// getters and setters
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getHeightFt() {
		return heightFt;
	}
	
	public void setHeightFt(String heightFt) {
		this.heightFt = heightFt;
	}
	
	public String getHeightIn() {
		return heightIn;
	}
	
	public void setHeightIn(String heightIn) {
		this.heightIn = heightIn;
	}
	
	public String getWeight() {
		return weight;
	}

	public void setWeight(String weight) {
		this.weight = weight;
	}
	
	public String getImg() {
		return img;
	}

	public void setImg(String string) {
		this.img = string;
	}
	
}
