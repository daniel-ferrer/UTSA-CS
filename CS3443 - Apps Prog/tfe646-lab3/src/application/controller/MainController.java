/**
 * 
 */
package application.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;

/**
 * @author Daniel Ferrer-Sosa (tfe646)
 *
 */

public abstract class MainController implements Initializable {
	@FXML AnchorPane background;
	@FXML ImageView shieldImg;
	@FXML ImageView captainamerica;
	@FXML ImageView ironman;
	@FXML ImageView hulk;
	@FXML ImageView blackwidow;
	@FXML ImageView thor;
	
	@FXML Label shieldText;
	@FXML Label captainamericaText;
	@FXML Label ironmanText;
	@FXML Label hulkText;
	@FXML Label blackwidowText;
	@FXML Label thorText;
	
	public MainController() {};
	
	
	@FXML public void initialize() {
		
		
	}
	
	@FXML protected void handler(ActionEvent e) {
		captainamericaText.setText("Hello World\n Testing string");
	}
	
	
}

	
