/**
 * 
 */
package application.model;

import java.util.ArrayList;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */
public class Act {
	private int number;
	private ArrayList<Scene> scenes;
	
	
	// getters and setters
	public int getActNumber() {
		return number;
	}
	
	public void setActNumber(int number) {
		this.number = number;
	}

	public ArrayList<Scene> getScenes() {
		return scenes;
	}
	
	public void setScenes(ArrayList<Scene> scenes) {
		this.scenes = scenes;
	}
}	
