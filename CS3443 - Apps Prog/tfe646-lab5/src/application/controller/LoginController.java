package application.controller;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import application.model.User;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

public class LoginController implements Initializable {
	@FXML
	private ImageView broadwayImg;
	@FXML
	private Label usernameLbl, passphraseLbl, errorMsg;
	@FXML
	private TextField usernameTF, passphraseTF;
	@FXML
	private Button loginBtn;
	
	// Helper vars
	private final String viewPath = "/main/resources/fxml/view/RoleView.fxml";

	@Override
	public void initialize(URL arg0, ResourceBundle arg1) { errorMsg.setVisible(false);	}
	
	// Event Listener on Button.onAction
	// User will be validated and shown error if invalid
	@FXML
	public void loginBtnClicked(ActionEvent event) {
		
		String username = usernameTF.getText();
		String password = passphraseTF.getText();

		User user = new User();
		user = user.validate(username, password);
		
		if(user == null) { errorMsg.setVisible(true); }
		else {
			errorMsg.setVisible(false);
			Node node = (Node) event.getSource();
			Stage stage = (Stage) node.getScene().getWindow();
			setRoleView(stage, user);
		}
	}
	
	// Helper method to change scene
	// Will send user back to RoleView.fxml
	public void setRoleView(Stage stage, User user) {
		try {
			FXMLLoader loader = new FXMLLoader (getClass().getResource(viewPath));
			Parent root = (Parent) loader.load();
			RoleViewController controller = loader.getController();
					
			controller.intakeUser(user); // load User's data

			Scene scene = new Scene(root, 800, 800);
			stage.setScene(scene);
			stage.setTitle("Role(s)");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
}
