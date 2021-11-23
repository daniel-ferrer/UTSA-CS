/**
 * 
 */
package application.model;

import javafx.scene.paint.Paint;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Avenger extends Person {
	// class attributes
	private String alias;
	private String gender;
	private String hasSpecialAbilities;
	private String _long;
	private String _lat;
	private Paint colorCode = null;
	
	// default constructor
	public Avenger() { }
	
	// constructor given @param values
	public Avenger(String name, String alias, String gender, String heightFt, String heightIn, String weight, String hasSpecialAbilities, String _long, String _lat) {
		super(name, heightFt, heightIn, weight);
		this.alias = alias;
		this._long = _long;
		this._lat = _lat;
		
		String imgPath = "data/" + alias.toLowerCase().replace(" ", "_") + ".jpg";
		super.setImg(("file:" + imgPath));
	}
	
	// getters and setters
	public String getAlias() {
		return alias;
	}

	public void setAlias(String alias) {
		this.alias = alias;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getHasSpecialAbilities() {
		return hasSpecialAbilities;
	}

	public void setHasSpecialAbilities(String hasSpecialAbilities) {
		this.hasSpecialAbilities = hasSpecialAbilities;
	}

	public String get_long() {
		return _long;
	}

	public void set_long(String _long) {
		this._long = _long;
	}

	public String get_lat() {
		return _lat;
	}

	public void set_lat(String _lat) {
		this._lat = _lat;
	}

	public Paint getColorCode() {
		return colorCode;
	}

	public void setColorCode(Paint colorCode) {
		this.colorCode = colorCode;
	}


}
